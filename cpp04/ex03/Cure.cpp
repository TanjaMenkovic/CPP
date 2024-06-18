/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:44:05 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:44:06 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	cout << "Cure: Default constructor called" << endl;
}

Cure::Cure(const Cure& cure): AMateria("cure")
{
	cout << "Cure: Copy constructor called" << endl;
	this->_type = cure._type;
}

Cure::~Cure(void)
{
	cout << "Cure: Destructor called, memory address = " << this << endl;
}

Cure& Cure::operator=(const Cure& cure)
{
	cout << "Cure: Assignation operator called" << endl;
	this->_type = cure._type;
	return (*this);
}

AMateria* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}
