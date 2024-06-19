/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:43:40 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:43:42 by tmenkovi         ###   ########.fr       */
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

class ICharacter;

class AMateria
{
	protected:
		string	_type;

	public:
		AMateria(void);
		AMateria(const string& type);
		AMateria(const AMateria& materia);

		virtual ~AMateria(void);
		AMateria& operator=(const AMateria& materia);

		const string& getType(void) const;

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};
