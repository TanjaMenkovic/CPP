/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:05:06 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:58:45 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap <" << name << "> has been called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &to_copy): ClapTrap(to_copy)
{
	std::cout << "Sub class (ScavTrap) copy constructor has been called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &original)
{
	if (this != &original)
	{
		this->_name = original._name;
		this->_hitPoints = original._hitPoints;
		this->_energyPoints = original._energyPoints;
		this->_attackDamage = original._attackDamage;
	}
	std::cout << "Copy assignment constructor has been called!" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target 
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScarvTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
