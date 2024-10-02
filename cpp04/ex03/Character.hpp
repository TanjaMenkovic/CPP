/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:43:56 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:49:37 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <iostream>
#include <string>

# define N_SLOTS	4

class Character: public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[N_SLOTS];
		int			_currIdx;

	public:
		Character(void);
		Character(std::string name);
		Character(const Character& character);
		~Character(void);
		Character& operator=(const Character& character);

		const std::string& getName(void) const;
        
		void equip(AMateria* materia);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
