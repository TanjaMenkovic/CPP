/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:26 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/17 17:10:27 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	cout << "Cat is created" << endl;
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Cat Brain couldn't be allocated!");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Cat::Cat(const Cat &copy): Animal()
{
	cout << "Cat Copy Constructor called" << endl;
	*this = copy;
}

Cat::~Cat()
{
	delete(this->_brain);
	cout << "Cat is destroyed!" << endl;
}

Cat &Cat::operator=(const Cat &src)
{
	cout << "Cat Assignation operator called" << endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Cat Brain couldn't be allocated!");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	*this->_brain = *src._brain;
	return *this;
}

void	Cat::makeSound(void)const
{
	cout << this->getType() << " says: MEEEEEEEOOOOOWWWWW!!!" << endl;
}

void	Cat::getIdeas(void)const
{
	for (int i = 0; i < 5; i++) // change number to 100 if you want to see all 100 ideas
		cout << i << ". Cat's idea is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAddress(i) << endl;
}

void	Cat::setIdea(size_t i, string idea)
{
		this->_brain->setIdea(i, idea);
}