#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("Louis");

	clap.attack("Jack");
	clap.beRepaired(50);
	clap.takeDamage(50);
}