# include "Dog.hpp"

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete(this->brain);
}

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(const Dog& other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignement constructor called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		*this->brain = *other.brain;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "wouf" << std::endl;
}

Brain* Dog::getBrain() {
	return (this->brain);
}