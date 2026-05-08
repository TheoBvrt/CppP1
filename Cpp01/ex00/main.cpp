#include "Zombie.hpp"

int main(void) {
	Zombie *newZ = newZombie("Mehdi");
	newZ->announce();

	randomChump("Teo");

	delete(newZ);
}