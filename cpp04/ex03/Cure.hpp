/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:44:13 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:44:14 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::cerr;

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& cure);
		~Cure(void);
		Cure& operator=(const Cure& cure);
		AMateria* clone(void) const;
		void use(ICharacter& target);
};
