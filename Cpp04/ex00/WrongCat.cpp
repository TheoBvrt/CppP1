#include "WrongCat.hpp"

WrongCat::~WrongCat() {
	std::cout << "Wrong cat destructor called" << std::endl;
}

WrongCat::WrongCat() {
	std::cout << "Wrong cat default constructor called" << std::endl;
	this->type = "Wrong cat";
}

WrongCat::WrongCat(const WrongCat& other) {
	std::cout << "Wrong cat copy destructor called" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "Wrong cat assignement constructor called" << std::endl;
	this->type = other.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCatSound" << std::endl;
}