#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    private:
        // there might be some attributes
    public:
        Cure( void );
        Cure( const Cure& other );
        ~Cure( void );

        Cure& operator=( const Cure& rightOne );

        AMateria* clone() const;

        void use(ICharacter& target);

};

#endif /* end of CURE_HPP */