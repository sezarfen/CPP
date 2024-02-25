#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
    std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
    // TODO: we can enhance with respect to the changes
}

MateriaSource::~MateriaSource( void )
{
    std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource* MateriaSource::operator=( const MateriaSource& rightOne )
{
    if (this == &rightOne)
        return (*this);
    // TODO: we can enhance with respect to the changes
}

void MateriaSource::learnMateria( AMateria* materia )
{

}

AMateria* createMateria( std::string const& type )
{
    
}