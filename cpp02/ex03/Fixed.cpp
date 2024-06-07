/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:03:02 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:03:04 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
//	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int inInt) : _value(inInt * (1 << Fixed::_bits)) {
//	cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float inFloat) : _value(roundf(inFloat * (1 << Fixed::_bits)) ) {
//	cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &to_copy) {
//	cout << "Copy constructor called" << endl;
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &original)
{
//	cout << "Copy assignment operator called" << endl;
	this->setRawBits(original.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {
//	cout << "Destructor called" << endl;
};

int Fixed::getRawBits(void) const
{
//	cout << "getRawBits() member function called" << endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	return (float)this->_value / (float)(1 << Fixed::_bits);
}

int Fixed::toInt(void) const {
	return this->_value >> Fixed::_bits;
}

ostream &operator<<(ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return stream;
}

bool Fixed::operator>(const Fixed &nbr) {
	return this->_value > nbr.getRawBits();
}

bool Fixed::operator<(const Fixed &nbr) {
	return this->_value < nbr.getRawBits();
}

bool Fixed::operator<=(const Fixed &nbr) {
	return this->_value <= nbr.getRawBits();
}

bool Fixed::operator>=(const Fixed &nbr) {
	return this->_value >= nbr.getRawBits();
}

bool Fixed::operator==(const Fixed &nbr) {
	return this->_value == nbr.getRawBits();
}

bool Fixed::operator!=(const Fixed &nbr) {
	return this->_value != nbr.getRawBits();
}

Fixed Fixed::operator+(const Fixed &nbr) {
	return Fixed( this->toFloat() + nbr.toFloat() );
}

Fixed Fixed::operator-(const Fixed &nbr) {
	return Fixed( this->toFloat() - nbr.toFloat() );
}

Fixed Fixed::operator*(const Fixed &nbr) {
	return Fixed ( this->toFloat() * nbr.toFloat() );
}

Fixed Fixed::operator/(const Fixed &nbr) {
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
