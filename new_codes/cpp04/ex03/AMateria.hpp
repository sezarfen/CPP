#pragma once // or maybe we can change with classical ifndef statements later on 

#include <iostream>

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria( std::string const & type );
        AMateria( void );
        AMateria( const AMateria& other );
        ~AMateria( void );

        AMateria& operator=( const AMateria& rightOne );

        std::string const & getType() const; //Returns the materia type

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
