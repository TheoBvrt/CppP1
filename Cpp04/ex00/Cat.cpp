#include "Cat.hpp"

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Assignment constructor called" << std::endl;
	this->type = other.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Miaou" << std::endl;
}

