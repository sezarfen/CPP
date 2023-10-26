#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::Zombie(){}

Zombie::~Zombie()
{
	std::cout << "Deconstructor called for " << this->_name << " , end of the scope or delete keyword used." << std::endl;
}

void Zombie::announce()
{
	std::cout << this->_name + ": " << "BraiiiiiiinnnzzzZ..." << std::endl; 
}

std::string Zombie::getName()
{
	return (this->_name);
}

void Zombie::setName(std::string name)
{
	this->_name = name;
}