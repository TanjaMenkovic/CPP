/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:40 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/17 17:10:41 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	cout << "Dog is created" << endl;
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain couldn't be allocated!");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
}

Dog::Dog(const Dog &copy): Animal()
{
	cout << "Dog Copy Constructor called" << endl;
	*this = copy;
}

Dog::~Dog()
{
	delete(this->_brain);
	cout << "Dog is destroyed!" << endl;
}

Dog &Dog::operator=(const Dog &src)
{
	cout << "Dog Assignation operator called" << endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	this->_brain = new Brain();
	if (this->_brain == NULL)
	{
		perror("Dog Brain couldn't be allocated!");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	*this->_brain = *src._brain;
	return *this;
}

void	Dog::makeSound(void) const
{
	cout << this->getType() << " says: AVV AVVVVV!!!" << endl;
}

void	Dog::getIdeas(void) const
{
	for (int i = 0; i < 5; i++) // change number to 100 if you want to see all 100 ideas
		cout << i << ". Dog's idea is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAddress(i) << endl;
}

void	Dog::setIdea(size_t i, string idea)
{
		this->_brain->setIdea(i, idea);
}