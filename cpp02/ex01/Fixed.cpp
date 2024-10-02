/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:01:39 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:27:02 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::customRound(float value) 
{
    return (value >= 0) ? static_cast<int>(value + 0.5f) : static_cast<int>(value - 0.5f);
}

Fixed::Fixed() : _value(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int inInt) : _value(inInt * (1 << Fixed::_bits)) 
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float inFloat) : _value(customRound(inFloat * (1 << Fixed::_bits)) ) 
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &to_copy) 
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &original)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(original.getRawBits());
	return *this;
}

Fixed::~Fixed() 
{
	std::cout << "Destructor called" << std::endl;
};

int Fixed::getRawBits() const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw) 
{
	this->_value = raw;
}

float Fixed::toFloat(void) const 
{
	return (float)this->_value / (float)(1 << Fixed::_bits);
}

int Fixed::toInt(void) const 
{
	return this->_value >> Fixed::_bits;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}
