/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmenkovi <tmenkovi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:01:39 by tmenkovi          #+#    #+#             */
/*   Updated: 2024/06/06 16:01:41 by tmenkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::customRound(float value) {
    return (value >= 0) ? static_cast<int>(value + 0.5f) : static_cast<int>(value - 0.5f);
}

Fixed::Fixed(void) : _value(0) {
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int inInt) : _value(inInt * (1 << Fixed::_bits)) {
	cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float inFloat) : _value(customRound(inFloat * (1 << Fixed::_bits)) ) {
	cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &to_copy) {
	cout << "Copy constructor called" << endl;
	*this = to_copy;
}

Fixed &Fixed::operator=(const Fixed &original)
{
	cout << "Copy assignment operator called" << endl;
	this->setRawBits(original.getRawBits());
	return *this;
}

Fixed::~Fixed(void) {
	cout << "Destructor called" << endl;
};

int Fixed::getRawBits(void) const
{
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
