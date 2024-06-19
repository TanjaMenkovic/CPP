/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:43:56 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:43:57 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

# define N_SLOTS	4

class Character: public ICharacter
{
	private:
		string	    _name;
		AMateria*	_inventory[N_SLOTS];
		int			_currIdx;

	public:
		Character(void);
		Character(string name);
		Character(const Character& character);
		~Character(void);
		Character& operator=(const Character& character);

		const string& getName(void) const;
        
		void equip(AMateria* materia);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
