# include "Dog.hpp"

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(const Dog& other) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignement constructor called" << std::endl;
	this->type = other.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "wouf" << std::endl;
}