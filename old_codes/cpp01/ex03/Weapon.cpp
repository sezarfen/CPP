#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::Weapon() {}

const std::string &Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}