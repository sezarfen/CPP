#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap fragTrap("FragTrap1");
	ScavTrap scavTrap("FragTrap1");

	fragTrap.attack("enemy1");
	scavTrap.attack("enemy2");
	
	fragTrap.highFivesGuys();
	scavTrap.guardGate();

	fragTrap.beRepaired(30);
	scavTrap.beRepaired(20);

	fragTrap.printInfo();
	scavTrap.printInfo();

	return (0);
}