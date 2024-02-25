#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
    this->current = 0;
    std::cout << "MateriaSource default constructor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
    // TODO: we can enhance with respect to the changes
}

MateriaSource::~MateriaSource( void )
{
    std::cout << "MateriaSource destructor called" << std::endl;

    for (int i = 0; i < this->current; i++)
        delete this->source[i];
}

MateriaSource* MateriaSource::operator=( const MateriaSource& rightOne )
{
    if (this == &rightOne)
        return (*this);
    // TODO: we can enhance with respect to the changes
}

void MateriaSource::learnMateria( AMateria* materia )
{
    if (this->current < 4)
    {
        this->source[this->materia] = materia;
        (this->current)++;
    }
}

AMateria* MateriaSource::createMateria( std::string const& type )
{
    int i = this->current;
    while (i >= 0)
    {
        if (this->source[i].getType() == type)
        {
            if (type == "ice")
                return (new Ice(this->source[i]));
            else
                return (new Cure(this->source[i]));
        }
        i--;
    }
}