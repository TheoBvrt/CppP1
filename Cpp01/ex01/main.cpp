#include "Zombie.hpp"

int main(void) {
	int N = 5;
	Zombie *tab = zombieHorde(N, "Mehdi");

	for (int i = 0; i < N; i++) {
		tab[i].announce();
	}

	delete[] tab;
}