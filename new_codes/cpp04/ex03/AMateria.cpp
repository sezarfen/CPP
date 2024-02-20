#include "AMateria.hpp"

AMateria::AMateria( void )
{
    std::cout << "AMateria's default constructor called" << std::endl;
    this->type = "Unknown"; // I DON'T KNOW IF THIS IS NECESSARY
}

AMateria::AMateria( std::string const& type )
{
    std::cout << "AMateria's std::string constructor called" << std::endl;
    this->type = type;
}

AMateria::~AMateria( void )
{
    std::cout << "Destructor called" << std::endl;
}

AMateria& AMateria::operator=( const AMateria& rightOne )
{
    this->type = rightOne.type;
}

std::string const& AMateria::getType( void ) const
{
    return (this->type);
}

// virtual AMateria* clone() const = 0; // is a pure virtual function

// virtual void AMateria::use(ICharacter& target)