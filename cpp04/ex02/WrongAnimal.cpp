/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:57 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:45:15 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* constructors */
WrongAnimal::WrongAnimal(): _type("default")
{
	std::cout << "Default WrongAnimal is created" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name): _type(name)
{
	std::cout << "WrongAnimal named " << name << " is created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = copy;
}

/* deconstructor */
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal is destroyed!" << std::endl;
} 

/* overloaded Operator */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

/* methods */
void WrongAnimal::makeSound(void)const
{
	std::cout << "This WrongAnimal is making only wrong sounds!" << std::endl;
}

/* getter */ 
std::string	WrongAnimal::getType(void)const
{
	return (this->_type);
}
