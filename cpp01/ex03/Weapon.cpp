/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:44:08 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:07:45 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string type)
{
	if (type.empty())
	{
		std::cout << "Please give a type to the weapon." << std::endl;
		return ;
	}

	this->_type = type;
}

const std::string& Weapon::getType()
{
	return this->_type;
}
