/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 08:43:29 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/03 08:43:30 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() const
{
	if (this->_weapon.getType().empty())
		std::cout << this->_name << " can't attack without a weapon."
			<< std::endl;
	else
		std::cout << this->_name << " attacks with their "
			<< this->_weapon.getType() << std::endl;
}
