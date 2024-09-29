/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:04:15 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/09/27 12:26:25 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	cout << "ClapTrap <" << name << "> has been called!" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &to_copy)
{
	this->_name = to_copy._name;
	this->_hitPoints = to_copy._hitPoints;
	this->_energyPoints = to_copy._energyPoints;
	this->_attackDamage = to_copy._attackDamage;
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
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	cout << "ClapTrap has been destroyed!" << endl;
};

void ClapTrap::attack(const string& target)
{
	if (this->_energyPoints == 0)
	{
		cout << "ClapTrap is out of energy points!" << endl;
		return ;
	}
	cout << "ClapTrap " << this->_name << " attacks " << target 
		<< ", causing " << this->_attackDamage << " points of damage!" << endl;
	this->_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hitPoints || this->_hitPoints == 0)
	{
		cout << "ClapTrap " << this->_name << " died." << endl;
		this->_hitPoints = 0;
		return ;
	}
	this->_hitPoints -= amount;
	cout << "ClapTrap " << this->_name << " took " << amount
		<< " points of damage and is left with " << _hitPoints << " hit points!" << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		cout << "ClapTrap is out of energy points!" << endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= 1;
	cout << "ClapTrap " << this->_name << " has been repaired and gained "
		<< amount << " hit points and is left with " << this->_hitPoints
		<< " hit points!" << endl;
}
