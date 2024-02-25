#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        // MateriaSource* source[4];
    public:
        MateriaSource( void );
        MateriaSource( const MateriaSource& other );
        ~MateriaSource( void );

        MateriaSource* operator=( const MateriaSource& rightOne );

        // override functions
        void learnMateria( AMateria* materia );
        AMateria* createMateria( std::string const& type );
}