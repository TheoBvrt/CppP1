#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
}

Animal::~Animal() {

}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	this->type = other.type;
	return *this;
}

void Animal::makeSound() {
	std::cout << "Animal make sound" << std::endl;
}

std::string Animal::getType() {
	return this->type;
}