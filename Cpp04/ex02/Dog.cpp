# include "Dog.hpp"

Dog::~Dog() {
	delete(this->brain);
}

Dog::Dog() {
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(const Dog& other) {
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	this->type = other.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "wouf" << std::endl;
}