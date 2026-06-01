#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap sc("Louis");
	ClapTrap cp("maxime");

	sc.attack("test");
	cp.attack("test");
}