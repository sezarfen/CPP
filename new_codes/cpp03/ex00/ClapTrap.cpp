#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void )
{
    std::cout << "ClapTrap default constructor called" << std::endl;

    this->name = "No name specified";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;

}

ClapTrap::ClapTrap( const ClapTrap& other )
{
    std::cout << "ClapTrap copy constructor called" << std::endl;

    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

ClapTrap::ClapTrap( std::string newName )
{
    std::cout << "ClapTrap std::string constructor called" << std::endl;

    this->name = newName;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap default destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=( const ClapTrap& rightOne )
{
    std::cout << "ClapTrap copy assignment operator called" << std::endl;
    if (this == &rightOne)
        return (*this);
    this->name = rightOne.name;
    this->hitPoints = rightOne.hitPoints;
    this->energyPoints = rightOne.energyPoints;
    this->attackDamage = rightOne.attackDamage;
    return (*this);
}

void ClapTrap::attack( const std::string& target )
{
    if (this->energyPoints <= 0)
    {
        std::cout << "Sorry ma boy, I am just out of energy points, see you fellas! yiiihhhaaa!!!" << std::endl;
        return ;
    }

    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    this->energyPoints--;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    std::cout << "ClapTrap " << this->name << " has taken a damage amount of " << amount << "." << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount )
{
    if (this->energyPoints <= 0)
    {
        std::cout << "Owww maaan not today, who just really needs energy points to repair itself?" << std::endl;
        return ;
    }

    std::cout << "ClapTrap '" << this->name << "' get " << amount << " hit points back." << std::endl; 
    this->energyPoints--;
}
