/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:43:46 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:07:59 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon)
{
	if (weapon.getType().empty())
	{
		std::cout << "Please provide a weapon." << std::endl;
		return ;
	}

	this->_weapon = &weapon;
}

void HumanB::attack() const
{
	if (!this->_weapon || this->_weapon->getType().empty())
	{
		std::cout << "You need a weapon before you attack."
			<< std::endl;
		return ;
	}

	std::cout << this->_name << " attacks with their "
		<< this->_weapon->getType() << std::endl;
}
