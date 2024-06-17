/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:57 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/17 17:10:58 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* constructors */
WrongAnimal::WrongAnimal(): _type("default")
{
	cout << "Default WrongAnimal is created" << endl;
}

WrongAnimal::WrongAnimal(string name): _type(name)
{
	cout << "WrongAnimal named " << name << " is created!" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	cout << "WrongAnimal Copy Constructor called" << endl;
	*this = copy;
}

/* deconstructor */
WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal is destroyed!" << endl;
} 

/* overloaded Operator */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	cout << "WrongAnimal Assignation operator called" << endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

/* methods */
void WrongAnimal::makeSound(void)const
{
	cout << "This WrongAnimal is making only wrong sounds!" << endl;
}

/* getter */ 
string	WrongAnimal::getType(void)const
{
	return (this->_type);
}
