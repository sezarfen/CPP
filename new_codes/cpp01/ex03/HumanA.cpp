#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : weapon(weapon)
{
	this->name = name;
}

void	HumanA::attack( void )
{
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}