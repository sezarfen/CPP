#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    this->current = 0;
    for (int i = 0; i < 4; i++)
        this->source[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource& other )
{
    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] != NULL)
        {
            if (other.source[i] != NULL)
            {
                delete this->source[i];
                if (other.source[i]->getType() == "ice")
                    this->source[i] = new Ice(other.source[i]);
                else
                    this->source[i] = new Cure(other.source[i]);
            }
        }
        else
        {
            if (other.source[i] != NULL)
            {
                if (other.source[i]->getType() == "ice")
                    this->source[i] = new Ice(other.source[i]);
                else
                    this->source[i] = new Cure(other.source[i]);
            }
        }
    }
    // TODO: we can enhance with respect to the changes
}

MateriaSource::~MateriaSource( void )
{
    std::cout << "MateriaSource destructor called" << std::endl;

    for (int i = 0; i < this->current; i++)
    {
        if (this->source[i] != NULL)
            delete this->source[i];
    }
}

MateriaSource* MateriaSource::operator=( const MateriaSource& other )
{
    if (this == &rightOne)
        return (*this);

    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] != NULL)
        {
            if (other.source[i] != NULL)
            {
                delete this->source[i];
                if (other.source[i]->getType() == "ice")
                    this->source[i] = new Ice(other.source[i]);
                else
                    this->source[i] = new Cure(other.source[i]);
            }
        }
        else
        {
            if (other.source[i] != NULL)
            {
                if (other.source[i]->getType() == "ice")
                    this->source[i] = new Ice(other.source[i]);
                else
                    this->source[i] = new Cure(other.source[i]);
            }
        }
    }
    return (*this);
}

void MateriaSource::learnMateria( AMateria* materia )
{
    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] == NULL)
            this->source[i] = materia;
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