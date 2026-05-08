#include "Zombie.hpp"

Zombie::~Zombie() {
	std::cout << this->name << ": deleted" << std::endl;
}

Zombie::Zombie(const std::string &name) {
	this->name = name;
}

void Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}