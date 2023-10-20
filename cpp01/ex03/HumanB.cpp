#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

void HumanB::attack()
{
	if (this->_weapon == NULL)
	{
		std::cout << "Does not have any weapons, attack stopped." << std::endl;
		return ;
	}
	std::cout 
		<< this->_name + " attacks with their " 
		<< this->_weapon->getType() 
		<< std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}