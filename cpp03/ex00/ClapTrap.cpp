//
// Created by TR on 20.10.2023.
//

#include "ClapTrap.hpp"

// CONSTRUCTOR AND DESTRUCTOR

ClapTrap::ClapTrap( void ) : hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Default constructor called." << std::endl;
    name = "Not Given Yet";
}

ClapTrap::ClapTrap( std::string name)
: hitPoints(10), energyPoints(10), attackDamage(0), name(name)
{
    std::cout << "std::string constructor called." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & clapTrap)
: hitPoints(clapTrap.hitPoints),
energyPoints(clapTrap.energyPoints),
attackDamage(clapTrap.attackDamage),
name(clapTrap.name)
{
    std::cout << "Copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called." << std::endl;
}

// PUBLIC MEMBER FUNCTIONS

void ClapTrap::attack( const std::string& target)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "I can't find that power inside of me :(" << std::endl;
        return ;
    }
    std::cout << "target " << target << " loose " << attackDamage << " health points : Attacker = " << "Claptrap " << name << std::endl;
    std::cout << "ClapTrap " << name << " loose 1 energy point" << std::endl;
    energyPoints--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0 || energyPoints <= 0)
    {
        std::cout << "I can't find that power inside of me :(" << std::endl;
        return ;
    }
    std::cout << amount << " amount hit points gained." << std::endl;
    std::cout << "ClapTrap " << name << " loose 1 energy point" << std::endl;
    hitPoints += amount;
    energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << name << " got " << amount << " of damage." << std::endl;
    hitPoints -= amount;
}

void ClapTrap::printInfo() {
    std::cout << "---CURRENT INFO---" << std::endl;
    std::cout << "name : " << name << std::endl;
    std::cout << "hitPoints : " << hitPoints << std::endl;
    std::cout << "energyPoints : " << energyPoints << std::endl;
    std::cout << "attackDamage : " << attackDamage << std::endl;
    std::cout << "------------------" << std::endl;
}

// OPERATOR OVERLOADS

ClapTrap & ClapTrap::operator=(const ClapTrap &clapTrap) {
    std::cout << "Assignment operator called " << std::endl;
    return (*this);
}
