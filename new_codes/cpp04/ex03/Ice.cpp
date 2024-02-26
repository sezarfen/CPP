#include "Ice.hpp"

Ice::Ice( void )
{
    this->type = "ice";
}

Ice::Ice( const Ice& other ) : AMateria(other)
{
    this->type = other.type;
}

Ice::~Ice( void )
{
    std::cout << "Ice class's default constructor called" << std::endl;
}

Ice& Ice::operator=( const Ice& rightOne )
{
    if (this == &rightOne)
        return (*this);
    this->type = rightOne.type;
    return (*this);
}

AMateria* Ice::clone( void ) const
{
    return (new Ice());
}

void Ice::use( ICharacter& target )
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}