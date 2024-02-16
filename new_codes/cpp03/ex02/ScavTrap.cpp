#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->name = "Unknown";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap( std::string newName )
{
    std::cout << "ScavTrap string::name constructor called" << std::endl;
    this->name = newName;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& other ) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=( const ScavTrap& rightOne )
{
    if (this == &rightOne)
        return (*this);
    this->name = rightOne.name;
    this->hitPoints = rightOne.hitPoints;
    this->energyPoints = rightOne.energyPoints;
    this->attackDamage = rightOne.attackDamage;
    return (*this);
}

void ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
