#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int inInt) : _value(inInt * (1 << Fixed::_bits)) {
	cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float inFloat) : _value(roundf(inFloat * (1 << Fixed::_bits)) ) {
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
	cout << "getRawBits() member function called" << endl;
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
