#pragma once

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* source[4];
        int current;
    public:
        MateriaSource( void );
        MateriaSource( const MateriaSource& other );
        ~MateriaSource( void );

        MateriaSource* operator=( const MateriaSource& rightOne );

        // override functions
        void learnMateria( AMateria* materia );
        AMateria* createMateria( std::string const& type );
}