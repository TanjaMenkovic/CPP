/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:06:42 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:06:43 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	cout << "Sub Class (FragTrap) constructor has been called" << endl;
}

FragTrap::~FragTrap(void)
{
	cout << "Sub Class (FragTrap) destructor has been called" << endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints == 0) {
        cout << "FragTrap "<< this->_name << " is out of energy points!" << endl;
        return ;
    }
	cout << "FragTrap " << this->_name << " says: High Fives!" << endl;
    this->_energyPoints -= 1;
}
