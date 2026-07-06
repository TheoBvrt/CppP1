
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

////////////////

Fixed::Fixed() : fpn(0) {
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return *this;
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

/////////////////


Fixed::Fixed(const int value) {
	std::cout << "Int constructor called\n";
	this->fpn = value * 256;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";
	this->fpn = roundf(value * (1 << fractional));
}


////////////////

std::ostream& operator<<(std::ostream &os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

///////////////


float Fixed::toFloat(void) const {
	return (this->fpn / 256.0f);
}

int Fixed::toInt(void) const {
	return (this->fpn / 256.0f);
}

int Fixed::getRawBits(void) const {
	return (fpn);
}

void Fixed::setRawBits(const int raw) {
	fpn = raw;
}