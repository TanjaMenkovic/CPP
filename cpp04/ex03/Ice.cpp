/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:44:43 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/18 17:44:44 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	cout << "Ice has beed created" << endl;
}

Ice::Ice(const Ice& ice): AMateria("ice")
{
	cout << "Ice: Copy constructor called" << endl;
	this->_type = ice._type;
}

Ice::~Ice(void)
{
	cout << "Ice has beed destroyed at address " << this << endl;
}

Ice& Ice::operator=(const Ice& ice)
{
	cout << "Ice: Assignation operator called" << endl;
	this->_type = ice._type;
	return (*this);
}

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}
