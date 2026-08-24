#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong animal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal() {
	std::cout << "Wrong animal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "Wrong animal copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	this->type = other.type;
	std::cout << "Wrong animal assignement operator called" << std::endl;
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimalSound" << std::endl;
}