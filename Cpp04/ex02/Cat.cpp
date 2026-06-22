#include "Cat.hpp"

Cat::~Cat() {
	delete(this->brain);
}

Cat::Cat() {
	this->brain = new Brain();
	this->type = "Cat";
}

Cat::Cat(const Cat& other) {
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	this->type = other.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Miaou" << std::endl;
}

