#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal() {

}

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	this->type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimalSound" << std::endl;
}