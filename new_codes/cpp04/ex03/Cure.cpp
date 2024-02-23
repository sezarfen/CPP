#include "Cure.hpp"

Cure::Cure( void )
{
    this->type = "cure";
}

Cure::Cure( const Cure& other )
{
    this->type = other.type;
}

Cure::~Cure( void )
{
    std::cout << "Cure class's destructor called" << std::endl;
}

Cure& Cure::operator=( const Cure& rightOne )
{
    if (this == &rightOne)
        return (*this);
    this->type = rightOne.type;
    return (*this);
}

AMateria* Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals "<< target.name << "’s wounds *" << std::endl;
}