#include "AMateria.hpp"

AMateria::AMateria( void )
{
    this->type = "AMateria";
}

AMateria::AMateria( std::string const & type )
{
    this->type = type;
}

AMateria::AMateria( const AMateria& other )
{
    this->type = other.type;
}

AMateria::~AMateria( void )
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=( const AMateria& rightOne )
{
    if (this == &rightOne)
        return (*this);
    this->type = rightOne.type;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    // will be return something later, when we declare ICharacter İnşaAllah
}