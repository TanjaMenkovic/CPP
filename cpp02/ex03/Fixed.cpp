/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:03:02 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/10/02 11:52:29 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::customRound(float value) 
{
    return (value >= 0) ? static_cast<int>(value + 0.5f) : static_cast<int>(value - 0.5f);
}

Fixed::Fixed(void) : _value(0) {}

Fixed::Fixed(const int inInt) : _value(inInt * (1 << Fixed::_bits)) {}

Fixed::Fixed(const float inFloat) : _value(customRound(inFloat * (1 << Fixed::_bits)) ) {}

Fixed::Fixed(const Fixed &to_copy) 
{
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &original)
{
	this->setRawBits(original.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {};

int Fixed::getRawBits(void) const
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

/* comparation operators */

bool Fixed::operator>(const Fixed &nbr) const
{
	return this->_value > nbr.getRawBits();
}

bool Fixed::operator<(const Fixed &nbr) const
{
	return this->_value < nbr.getRawBits();
}

bool Fixed::operator<=(const Fixed &nbr) const
{
	return this->_value <= nbr.getRawBits();
}

bool Fixed::operator>=(const Fixed &nbr) const
{
	return this->_value >= nbr.getRawBits();
}

bool Fixed::operator==(const Fixed &nbr) const
{
	return this->_value == nbr.getRawBits();
}

bool Fixed::operator!=(const Fixed &nbr) const
{
	return this->_value != nbr.getRawBits();
}

/* arithmetic operators */

Fixed Fixed::operator+(const Fixed &nbr) const
{
	return Fixed( this->toFloat() + nbr.toFloat() );
}

Fixed Fixed::operator-(const Fixed &nbr) const
{
	return Fixed( this->toFloat() - nbr.toFloat() );
}

Fixed Fixed::operator*(const Fixed &nbr) const
{
	return Fixed ( this->toFloat() * nbr.toFloat() );
}

Fixed Fixed::operator/(const Fixed &nbr) const
{
	return Fixed ( this->toFloat() / nbr.toFloat() );
}

/* increment/decrement operators */

// pre-increment
Fixed &Fixed::operator++(void)
{
	this->_value += 1;
	return *this;
}

// post-increment
Fixed Fixed::operator++(int)
{
	Fixed tmp(this->_value * toFloat());
	this->_value += 1;
	return tmp;
}

// pre-decrement
Fixed &Fixed::operator--(void)
{
	this->_value -= 1;
	return *this;
}

// post-decrement
Fixed Fixed::operator--(int)
{
	Fixed tmp(this->_value * toFloat());
	this->_value -= 1;
	return tmp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

/* max/min */

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
