/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:05:53 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:23:44 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Super Class (ClapTrap) default constructor <" << "default"
		<< "> has been called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Super Class (ClapTrap) default constructor <" << name
		<< "> has been called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &to_copy)
{
	this->_name = to_copy._name;
	this->_hitPoints = to_copy._hitPoints;
	this->_energyPoints = to_copy._energyPoints;
	this->_attackDamage = to_copy._attackDamage;
	std::cout << "Super Class (ClapTrap) copy constructor has been called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &original)
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

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor has been called" << std::endl;
};

void ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap is out of energy points!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << "!" << std::endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hitPoints || this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " died." << std::endl;
		this->_hitPoints = 0;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount
		<< " points of damage and is left with " << _hitPoints << " hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap is out of energy points!" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " has been repaired and gained "
		<< amount << " hit points and is left with " << this->_hitPoints
		<< " hit points!" << std::endl;
}
