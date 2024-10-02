/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:44:05 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:50:04 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure has beed created" << std::endl;
}

Cure::Cure(const Cure& cure): AMateria("cure")
{
	std::cout << "Cure: Copy constructor called" << std::endl;
	this->_type = cure._type;
}

Cure::~Cure(void)
{
	std::cout << "Cure has beed destroyed at address " << this << std::endl;
}

Cure& Cure::operator=(const Cure& cure)
{
	std::cout << "Cure: Assignation operator called" << std::endl;
	this->_type = cure._type;
	return (*this);
}

AMateria* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
