#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* materias[4];
        int current;
    public:
        Character( void );
        Character( const Character& other );
        Character( std::string const& name );
        ~Character( void );

        Character& operator=( const Character& rightOne );

        // override functions
        std::string const & getName() const;   // this might need to have private name attribute
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
}

#endif /* end of CHARACTER_HPP */