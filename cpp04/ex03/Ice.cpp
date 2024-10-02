/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:44:43 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 15:50:27 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Ice has beed created" << std::endl;
}

Ice::Ice(const Ice& ice): AMateria("ice")
{
	std::cout << "Ice: Copy constructor called" << std::endl;
	this->_type = ice._type;
}

Ice::~Ice(void)
{
	std::cout << "Ice has beed destroyed at address " << this << std::endl;
}

Ice& Ice::operator=(const Ice& ice)
{
	std::cout << "Ice: Assignation operator called" << std::endl;
	this->_type = ice._type;
	return (*this);
}

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
