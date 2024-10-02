/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:43:31 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:47:45 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"AMateria.hpp"

AMateria::AMateria(void): _type("Unknown type")
{
	std::cout << "Abstract materia has beed created" << std::endl;
}

AMateria::AMateria(const std::string& type): _type(type)
{
	std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& materia): _type(materia._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria has beed destroyed at address " << this << std::endl;
}

AMateria& AMateria::operator=(const AMateria& materia)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	this->_type = materia._type;
	return (*this);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria abstractly used on " << target.getName() << " *" ;
}

const std::string& AMateria::getType(void) const
{
	return (this->_type);
}
