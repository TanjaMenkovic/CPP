/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:02:28 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:02:29 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::customRound(float value) 
{
    return (value >= 0) ? static_cast<int>(value + 0.5f) : static_cast<int>(value - 0.5f);
}

Fixed::Fixed(void) : _value(0) 
{
}

Fixed::Fixed(const int inInt) : _value(inInt * (1 << Fixed::_bits)) 
{
}

Fixed::Fixed(const float inFloat) : _value(customRound(inFloat * (1 << Fixed::_bits)) ) 
{
}

Fixed::Fixed(const Fixed &to_copy) 
{
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &original)
{
	this->setRawBits(original.getRawBits());
	return *this;
}

Fixed::~Fixed(void) 
{
}

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

ostream &operator<<(ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}

bool Fixed::operator>(const Fixed &nbr) 
{
	return this->_value > nbr.getRawBits();
}

bool Fixed::operator<(const Fixed &nbr) 
{
	return this->_value < nbr.getRawBits();
}

bool Fixed::operator<=(const Fixed &nbr) 
{
	return this->_value <= nbr.getRawBits();
}

bool Fixed::operator>=(const Fixed &nbr) 
{
	return this->_value >= nbr.getRawBits();
}

bool Fixed::operator==(const Fixed &nbr) 
{
	return this->_value == nbr.getRawBits();
}

bool Fixed::operator!=(const Fixed &nbr) 
{
	return this->_value != nbr.getRawBits();
}

Fixed Fixed::operator+(const Fixed &nbr) 
{
	return Fixed( this->toFloat() + nbr.toFloat() );
}

Fixed Fixed::operator-(const Fixed &nbr) 
{
	return Fixed( this->toFloat() - nbr.toFloat() );
}

Fixed Fixed::operator*(const Fixed &nbr) 
{
	return Fixed ( this->toFloat() * nbr.toFloat() );
}

Fixed Fixed::operator/(const Fixed &nbr) 
{
	return Fixed ( this->toFloat() / nbr.toFloat() );
}

// pre-increment
Fixed &Fixed::operator++(void)
{
	this->_value += 1;
	return *this;
}

// post-increment
Fixed Fixed::operator++(int)
{
	// copy before increment
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
