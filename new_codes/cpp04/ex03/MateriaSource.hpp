#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria* source[4];
    public:
        MateriaSource( void );
        MateriaSource( const MateriaSource& other );
        ~MateriaSource( void );

        MateriaSource& operator=( const MateriaSource& rightOne );

        // override functions
        void learnMateria( AMateria* materia );
        AMateria* createMateria( std::string const& type );
};

#endif /* MATERIASOURCE_HPP */