/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:43:40 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:47:58 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria(void);
		AMateria(const std::string& type);
		AMateria(const AMateria& materia);

		virtual ~AMateria(void);
		AMateria& operator=(const AMateria& materia);

		const std::string& getType(void) const;

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};
