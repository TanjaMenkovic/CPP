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
}

Cat::Cat(const Cat &copy): Animal()
{
	cout << "Cat Copy Constructor called" << endl;
	*this = copy;
}

Cat::~Cat()
{
	cout << "Cat is destroyed!" << endl;
}

Cat &Cat::operator=(const Cat &src)
{
	cout << "Cat Assignation operator called" << endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void	Cat::makeSound(void)const
{
	cout << this->getType() << " says: MEEEEEEEOOOOOWWWWW!!!" << endl;
}
