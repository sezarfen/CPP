#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    private:
        // there might be some attributes

    public:
        Ice( void );
        Ice( const Ice& other );
        ~Ice( void );

        Ice& operator=( const Ice& rightOne );

        // override
        AMateria* clone() const;

        // override
        void use( ICharacter& target );
};

#endif /* end of ICE_HPP */