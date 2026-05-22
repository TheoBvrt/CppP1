
#include "Fixed.hpp"
#include <iostream>
#include <cmath>

////////////////

Fixed::Fixed() : fpn(0) {
	// std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &other) {
	this->fpn = other.fpn;
	// std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy assignment operator called\n";
	if (this == &other)
    	return *this;
	this->setRawBits(other.getRawBits());
  	return *this;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called\n";
}

/////////////////


bool Fixed::operator>(const Fixed& other) const {
	return this->fpn > other.fpn;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->fpn < other.fpn;
}


bool Fixed::operator>=(const Fixed& other) const {
	return this->fpn >= other.fpn;
}


bool Fixed::operator<=(const Fixed& other) const {
	return this->fpn <= other.fpn;
}


bool Fixed::operator==(const Fixed& other) const {
	return this->fpn == other.fpn;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->fpn != other.fpn;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed fixed;

	fixed.fpn = this->fpn + other.fpn;
	return fixed;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed fixed;

	fixed.fpn = this->fpn - other.fpn;
	return fixed;
}


Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;

	result.fpn = (this->fpn * other.fpn) >> fractional;
	return result;
}


Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;

	result.fpn = (this->fpn << fractional) / other.fpn;
	return result;
}

Fixed& Fixed::operator++() {
	this->fpn ++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = (*this);

	this->fpn++;
	return temp;
}

Fixed& Fixed::operator--() {
	this->fpn --;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp = (*this);

	this->fpn--;
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed& b) {
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed &a, Fixed& b) {
		if (a > b)
		return a;
	return b;
}


const Fixed& Fixed::min(const Fixed &a, const Fixed& b) {
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}


Fixed::Fixed(const int value) {
	// std::cout << "Int constructor called\n";
	this->fpn = value * 256;
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructor called\n";
	this->fpn = roundf(value * (1 << fractional));
}


////////////////

std::ostream& operator<<(std::ostream &os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}

///////////////


float Fixed::toFloat(void) const {
	return (float)this->fpn / (1 << fractional);
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