#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
: _weapon(weapon)
{
	this->_name = name;
}

void HumanA::attack()
{
	std::cout 
		<< this->_name + " attacks with their " 
		<< this->_weapon.getType() 
		<< std::endl;
}