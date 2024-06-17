/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:09 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/17 17:10:10 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* constructors */
Animal::Animal(): _type("default")
{
	cout << "Default animal is created" << endl;
}

Animal::Animal(string name): _type(name)
{
	cout << "Animal named " << name << " is created!" << endl;
}

Animal::Animal(const Animal &copy)
{
	cout << "Animal Copy Constructor called" << endl;
	*this = copy;
}

/* deconstructor */
Animal::~Animal()
{
	cout << "Animal is destroyed!" << endl;
} 

/* overloaded Operator */
Animal &Animal::operator=(const Animal &src)
{
	cout << "Animal Assignation operator called" << endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

/* methods */
void Animal::makeSound(void)const
{
	cout << "This animal doesn't make any sound." << endl;
}

/* getter */ 
string	Animal::getType(void)const
{
	return (this->_type);
}
