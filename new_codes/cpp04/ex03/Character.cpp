#include "Character.hpp"

Character::Character( void )
{
    this->current = 0;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character( const Character& other )
{
    this->name = other.name;

    // TODO: deep copy might needed here
}

Character::~Character( void )
{
    std::cout << "Character class destructor called" << std::endl;
}

Character& Character::operator=( const Character& other )
{
    if (this == &other)
        return (*this);
    
    this->name = other.name;

    // TODO: deep copy might needed here

    return (*this);
}

std::string const & Character::getNName() const
{
    return (this->name);
}

void Character::equip( AMateria* m )
{
    // TODO: Some logic might be needed here, to delete old one if the current is greater
    // than 3 and so on
    materias[current] = m;
}