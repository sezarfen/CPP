# include "FragTrap.hpp"


FragTrap::FragTrap()
{
	std::cout << "FragTrap constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "FragTrap std::string constructor called by " << this->_name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor is called" << std::endl;
}

void FragTrap::attack(const std::string & name)
{
	if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "I can't find that power inside of me :(" << std::endl;
        return ;
    }
	std::cout << "FragTrap " << this->_name << " attacked to " << name << " given " << attackDamage << " damage" << std::endl;
	this->energyPoints--;
}

void FragTrap::highFivesGuys()
{
	std::cout << "Cammooon give me a high five!" << std::endl;
}
