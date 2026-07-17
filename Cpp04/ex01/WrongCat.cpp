#include "WrongCat.hpp"

WrongCat::~WrongCat() {

}

WrongCat::WrongCat() {
	this->type = "Wrong cat";
}

WrongCat::WrongCat(const WrongCat& other) {
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	this->type = other.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCatSound" << std::endl;
}