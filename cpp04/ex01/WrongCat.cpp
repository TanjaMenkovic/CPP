/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:15 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/17 17:11:16 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "WrongCat";
	cout << "WrongCat is created" << endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal()
{
	cout << "WrongCat Copy Constructor called" << endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat is destroyed!" << endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	cout << "Cat Assignation operator called" << endl;
	if (this == &src)
		return *this;

	this->_type = src._type;
	return *this;
}

void	WrongCat::makeSound(void)const
{
	cout << this->getType() << " says: HEEEELLL YEEEAAAH!!!" << endl;
}
