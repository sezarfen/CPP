#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon weapon )
{
	this->weapon(weapon.getType());
	this->name = name;
}

void	HumanA::attack( void )
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}