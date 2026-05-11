#include "HumanB.hpp"

HumanB::HumanB(const std::string name) : name(name){
	this->weapon = NULL;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks  with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}