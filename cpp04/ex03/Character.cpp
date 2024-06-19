/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:43:48 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:43:49 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void): _name("Unnamed"), _currIdx(0)
{
	cout << "Character has beed created." << endl;
	for (int i = 0; i < N_SLOTS; i++)
		this->_inventory[i] = NULL;
}

Character::Character(string name ): _name(name), _currIdx(0)
{
	cout << "Character: Name constructor called" << endl;
	for (int i = 0; i < N_SLOTS; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& character): _name(character._name), _currIdx(character._currIdx)
{
	cout << "Character: Copy constructor called" << endl;
	for (int i = 0; i < N_SLOTS; i++)
	{
		this->_inventory[i] = NULL;
		if (character._inventory[i] != NULL)
			this->_inventory[i] = character._inventory[i]->clone();
	}
}

Character::~Character(void)
{
	cout << "Character has beed destroyed at address " << this << endl;
	for (int i = 0; i < N_SLOTS; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}

Character&	Character::operator=(const Character& character)
{
	cout << "Character: Assignation operator called" << endl;
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

const string&	Character::getName(void) const
{
	return ( this->_name );
}

void	Character::equip(AMateria* m)
{
	int i = 0;

	if (!m)
	{
		cout << this->_name << " tried to equip nothing and it did nothing" << endl;
		return ;
	}
	while ((this->_inventory)[i] != NULL && i < 4)
		i++;
	if (i >= 4)
	{
		cout << this->_name << " can't equip more than 4 Materia" << endl;
		return ;
	}
	(this->_inventory)[i] = m;
	cout << this->_name << " equipped materia " << m->getType() << " in slot " << i << endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		cout << this->_name << " tried to unequip nothing at slot " << idx << " and it did nothing" << endl;
	else if (!(this->_inventory)[idx])
		cout << this->_name << " has nothing equipped at slot " << idx << " so he can't unequip it" << endl;
	else
	{
		AMateria *ptr = (this->_inventory)[idx];
		cout << this->_name << " unequipped " << ptr->getType() << " at slot "<< idx << endl;
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