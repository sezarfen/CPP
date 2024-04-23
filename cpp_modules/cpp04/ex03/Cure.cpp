#include "Cure.hpp"

Cure::Cure( void )
{
    this->type = "cure";
}

Cure::Cure( const Cure& other ) : AMateria(other)
{
    this->type = other.type;
}

Cure::~Cure( void )
{
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
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}