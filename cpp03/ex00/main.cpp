//
// Created by TR on 20.10.2023.
//

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("Robot1");
	ClapTrap cp2;

	clapTrap.attack("Enemy");
	clapTrap.beRepaired(20);
	clapTrap.printInfo();

	clapTrap.takeDamage(20);
	clapTrap.printInfo();
	
	std::cout << "other constructors" << std::endl;
	cp2 = clapTrap;	
	cp2.attack("Enemy2");
	cp2.printInfo();
	return (0);
}
