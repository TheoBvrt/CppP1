#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *zTab = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zTab[i].setName(name);
	}
	return (zTab);
}