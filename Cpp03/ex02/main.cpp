#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap sc("Louis");
	ClapTrap cp("maxime");
	FragTrap ft("mehdi");

	sc.attack("test");
	cp.attack("test");
	ft.highFivesGuys();
	ft.attack("bot");
}