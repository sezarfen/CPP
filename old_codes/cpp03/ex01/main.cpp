#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav(">The new Scav<");

	scav.attack("The Entity");

	scav.guardGate();
	scav.printInfo();

	return (0);
}