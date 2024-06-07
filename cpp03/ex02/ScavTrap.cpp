/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:07:07 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:07:09 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	cout << "Sub Class (ScavTrap) constructor has been called" << endl;
}

ScavTrap::~ScavTrap(void)
{
	cout << "Sub Class (ScavTrap) destructor has been called" << endl;
}

void ScavTrap::attack(const string& target)
{
	if (this->_energyPoints == 0)
	{
		cout << "ScavTrap is out of energy points!" << endl;
		return ;
	}
	cout << "ScavTrap " << this->_name << " attacks " << target << "!" << endl;
	this->_energyPoints -= 1;
}

void ScavTrap::guardGate(void) {
	cout << "ScarvTrap " << this->_name << " is now in Gate keeper mode!" << endl;
}
