#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "Scavtrap Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Scavtrap default constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "Scavtrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) { 
	std::cout << "Scavtrap Assignment constructor called" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->attackDamage = other.attackDamage;
	this->energyPoints = other.energyPoints;
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << "Scavtrap " << this->name << "is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->energyPoints < 1)
		return;
	std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << attackDamage << " points of damage" << std::endl;
	this->energyPoints --;
}