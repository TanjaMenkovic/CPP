/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:43:48 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:49:08 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name("Unnamed"), _currIdx(0)
{
	std::cout << "Character has beed created." << std::endl;
	for (int i = 0; i < N_SLOTS; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name ): _name(name), _currIdx(0)
{
	std::cout << "Character: Name constructor called" << std::endl;
	for (int i = 0; i < N_SLOTS; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& character): _name(character._name), _currIdx(character._currIdx)
{
	std::cout << "Character: Copy constructor called" << std::endl;
	for (int i = 0; i < N_SLOTS; i++)
	{
		this->_inventory[i] = NULL;
		if (character._inventory[i] != NULL)
			this->_inventory[i] = character._inventory[i]->clone();
	}
}

Character::~Character(void)
{
	std::cout << "Character has beed destroyed at address " << this << std::endl;
	for (int i = 0; i < N_SLOTS; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

Character&	Character::operator=(const Character& character)
{
	std::cout << "Character: Assignation operator called" << std::endl;
	if (this != &character)
	{
		for (int i = 0; i < N_SLOTS; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			this->_inventory[i] = NULL;
			if (character._inventory[i] != NULL)
				this->_inventory[i] = character._inventory[i]->clone();
		}
		this->_currIdx = character._currIdx;
	}
	return (*this);
}

const std::string&	Character::getName(void) const
{
	return ( this->_name );
}

void	Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
	{
		std::cout << this->_name << " tried to equip nothing and it did nothing" << std::endl;
		return ;
	}
	while ((this->_inventory)[i] != NULL && i < 4)
		i++;
	if (i >= 4)
	{
		std::cout << this->_name << " can't equip more than 4 Materia" << std::endl;
		return ;
	}
	(this->_inventory)[i] = m;
	std::cout << this->_name << " equipped materia " << m->getType() << " in slot " << i << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		std::cout << this->_name << " tried to unequip nothing at slot " << idx << " and it did nothing" << std::endl;
	else if (!(this->_inventory)[idx])
		std::cout << this->_name << " has nothing equipped at slot " << idx << " so he can't unequip it" << std::endl;
	else
	{
		AMateria *ptr = (this->_inventory)[idx];
		std::cout << this->_name << " unequipped " << ptr->getType() << " at slot "<< idx << std::endl;
		(this->_inventory)[idx] = 0;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= N_SLOTS || this->_inventory[idx] == NULL)
		return ;
	this->_inventory[idx]->use(target);
}

// void	Character::printMaterias(void)
// {
// 	for (int i = 0; i < N_SLOTS; i++)
// 	{
// 		if (this->_inventory[i] != NULL)
// 			cout << "invetory[ " << i << " ] = " << this->_inventory[i] << endl;
// 		else
// 			cout << "invetory[ " << i << " ] = " << "Empty" << endl;
// 	}
// }

// void	Character::printTrash(void)
// {
// 	AMateriaNode*	tmp;
// 	int				i;

// 	if (this->_floor != NULL)
// 	{
// 		i = 0;
// 		tmp = this->_floor->getFirst();
// 		while (tmp != NULL)
// 		{
// 			cout << "Trash[ " << i << " ] = " << tmp->getContent() << endl;
// 			tmp = tmp->getNext();
// 			i++;
// 		}
// 	}
// 	else
// 		cout << "Empty" << endl;
// }