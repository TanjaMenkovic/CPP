/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:10:09 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:36:28 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* constructors */
Animal::Animal(): _type("default")
{
	std::cout << "Default animal is created" << std::endl;
}

Animal::Animal(std::string name): _type(name)
{
	std::cout << "Animal named " << name << " is created!" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = copy;
}

/* deconstructor */
Animal::~Animal()
{
	std::cout << "Animal is destroyed!" << std::endl;
} 

/* overloaded Operator */
Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

/* methods */
void Animal::makeSound(void)const
{
	std::cout << "This animal doesn't make any sound." << std::endl;
}

/* getter */ 
std::string	Animal::getType(void)const
{
	return (this->_type);
}
