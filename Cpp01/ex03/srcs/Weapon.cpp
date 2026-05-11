#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type) {}

void Weapon::setType(std::string _value)
{
	this->type = _value;
}

const std::string& Weapon::getType() const
{
	return (type);
}