/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:06:42 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:19:59 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Sub Class (FragTrap) constructor has been called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Sub Class (FragTrap) constructor has been called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &to_copy): ClapTrap(to_copy)
{
	std::cout << "Sub class (FragTrap) copy constructor has been called!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &original)
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

FragTrap::~FragTrap(void)
{
	std::cout << "Sub Class (FragTrap) destructor has been called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_energyPoints == 0) {
        std::cout << "FragTrap "<< this->_name << " is out of energy points!" << std::endl;
        return ;
    }
	std::cout << "FragTrap " << this->_name << " says: High Fives!" << std::endl;
    this->_energyPoints -= 1;
}
