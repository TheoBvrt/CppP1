#include "FragTrap.hpp"

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap defualt constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap Assignment constructor called" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap gives a high five" << std::endl;
}