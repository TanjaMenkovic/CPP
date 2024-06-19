/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:43:31 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:43:34 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"AMateria.hpp"

AMateria::AMateria(void): _type("Unknown type")
{
	cout << "Abstract materia has beed created" << endl;
}

AMateria::AMateria(const string& type): _type(type)
{
	cout << "AMateria type constructor called" << endl;
}

AMateria::AMateria(const AMateria& materia): _type(materia._type)
{
	cout << "AMateria copy constructor called" << endl;
}

AMateria::~AMateria(void)
{
	cout << "AMateria has beed destroyed at address " << this << endl;
}

AMateria& AMateria::operator=(const AMateria& materia)
{
	cout << "AMateria assignation operator called" << endl;
	this->_type = materia._type;
	return (*this);
}

void AMateria::use(ICharacter& target)
{
	cout << "* AMateria abstractly used on " << target.getName() << " *" ;
}

const string& AMateria::getType(void) const
{
	return (this->_type);
}
