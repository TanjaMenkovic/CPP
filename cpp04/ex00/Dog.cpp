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
}

Dog::Dog(const Dog &copy): Animal()
{
	cout << "Dog Copy Constructor called" << endl;
	*this = copy;
}

Dog::~Dog()
{
	cout << "Dog is destroyed!" << endl;
}

Dog &Dog::operator=(const Dog &src)
{
	cout << "Dog Assignation operator called" << endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void	Dog::makeSound(void)const
{
	cout << this->getType() << " says: AVV AVVVVV!!!" << endl;
}
