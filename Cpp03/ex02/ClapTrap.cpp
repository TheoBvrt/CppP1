#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::~ClapTrap() {
std::cout << "ClapTrap Default destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "ClapTrapCopy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap Assignment constructor called" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->energyPoints < 1)
		return;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << attackDamage << " points of damage" << std::endl;
	this->energyPoints --;
}

void ClapTrap::takeDamage(unsigned int amount) {
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " took" << amount << " damage | healthPoint: " << this->hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoints < 1)
		return;
	this->hitPoints += amount;
	this->energyPoints --;

	std::cout << "ClapTrap " << this->name << " regained " << amount << " health point | healthPoint: " << this->hitPoints << std::endl;
}