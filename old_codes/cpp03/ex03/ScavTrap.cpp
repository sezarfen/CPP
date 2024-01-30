#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap constructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap std::string constructor called by " << this->_name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor is called" << std::endl;
}

void ScavTrap::attack(const std::string & name)
{
	if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "I can't find that power inside of me :(" << std::endl;
        return ;
    }
	std::cout << "ScavTrap " << this->_name << " attacked to " << name << " given " << attackDamage << " damage" << std::endl;
	this->energyPoints--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}