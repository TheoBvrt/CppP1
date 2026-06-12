# include "Dog.hpp"

Dog::~Dog() {

}

Dog::Dog() {
	this->type = "Dog";
}

Dog::Dog(const Dog& other) {
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	this->type = other.type;
	return *this;
}

void Dog::makeSound() {
	std::cout << "wouf" << std::endl;
}