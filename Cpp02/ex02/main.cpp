#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// Fixed a(11);
	// Fixed b(11);
	// std::cout << (a > b) << std::endl;
	// std::cout << (a < b) << std::endl;
	// std::cout << (a != b) << std::endl;
	// std::cout << (a >= b) << std::endl;
	// std::cout << (a <= b) << std::endl;

	// std::cout << (a + b) << std::endl;
	// std::cout << (a - b) << std::endl;
	// std::cout << (a * b) << std::endl;
	// std::cout << (a / b) << std::endl;

	// Fixed a;
	// a.setRawBits(704);

	// std::cout << a.toFloat() << std::endl;
	return 0;
}