#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
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
                    this->source[i] = new Ice((Ice &)*(other.source[i]));
                else
                    this->source[i] = new Cure((Cure &)*(other.source[i]));
            }
        }
        else
        {
            if (other.source[i] != NULL)
            {
                if (other.source[i]->getType() == "ice")
                    this->source[i] = new Ice((Ice &)*(other.source[i]));
                else
                    this->source[i] = new Cure((Cure &)*(other.source[i]));
            }
        }
    }
}

MateriaSource::~MateriaSource( void )
{
    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] != NULL)
        {
            delete this->source[i];
            this->source[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=( const MateriaSource& other )
{
    if (this == &other)
        return (*this);

    for (int i = 0; i < 4; i++)
    {
        if (this->source[i] != NULL)
        {
            if (other.source[i] != NULL)
            {
                delete this->source[i];
                if (other.source[i]->getType() == "ice")
                    this->source[i] = new Ice((Ice &)*(other.source[i]));
                else
                    this->source[i] = new Cure((Cure &)*(other.source[i]));
            }
        }
        else
        {
            if (other.source[i] != NULL)
            {
                if (other.source[i]->getType() == "ice")
                    this->source[i] = new Ice((Ice &)*(other.source[i]));
                else
                    this->source[i] = new Cure((Cure &)*(other.source[i]));
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
        {
            if (materia->getType() == "ice")
                this->source[i] = materia; // there is the base of the leak, subject referes interesting
            else
                this->source[i] = materia;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria( std::string const& type )
{
    int i = 3;
    while (i >= 0)
    {
        if (this->source[i] != NULL && this->source[i]->getType() == type)
        {
            if (type == "ice")
                return (new Ice((Ice &)*(this->source[i])));
            else
                return (new Cure((Cure &)*(this->source[i])));
        }
        i--;
    }
    return (0);
}