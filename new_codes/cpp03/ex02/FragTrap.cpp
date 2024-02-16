#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
    std::cout << "FragTrap default constructor called" << std::endl;   
    this->name = "Unknown";
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;   
}

FragTrap::FragTrap( std::string newName ) : ClapTrap(newName)
{
    std::cout << "FragTrap std::string constructor called" << std::endl;   
    // we have to set these attributes seperately because subject explicitly says their values
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap default destructor called" << std::endl;
}

FragTrap& FragTrap::operator=( const FragTrap& rightOne )
{
    if (this == &rightOne)
        return (*this);
    this->name = rightOne.name;
    this->energyPoints = rightOne.energyPoints;
    this->hitPoints = rightOne.hitPoints;
    this->attackDamage = rightOne.attackDamage;
    return (*this);
}

void FragTrap::highFivesGuys( void )
{
    std::cout << "Come on maaan, give me a high five! Yesss that's what I am talking about" << std::endl;
}