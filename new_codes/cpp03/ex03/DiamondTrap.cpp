#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

DiamondTrap::DiamondTrap( std::string name )
{
    this->name = name;
    ClapTrap::name = name + "_clap_name";
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& rightOne )
{
    std::cout << "DiamondTrap copy assignment operator called" << std::endl;
    if (this == &rightOne)
        return (*this);
    this->name = rightOne.name;
    this->hitPoints = rightOne.hitPoints;
    this->energyPoints = rightOne.energyPoints;
    this->attackDamage = rightOne.attackDamage;
    return (*this);
}

void DiamondTrap::attack( std::string enemy )
{
    ScavTrap::attack(enemy);
}

void DiamondTrap::whoAmI( void )
{
    std::cout << "My name is '" << this->name << "'" << std::endl;
    std::cout << "ClapTrap's name is '" << ClapTrap::name << "'" << std::endl;
}
