#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        // there might be some attributes
    public:
        Character( void );
        Character( const Character& other );
        ~Character( void );

        Character& operator=( const Character& rightOne );

        // override functions
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
}

#endif /* end of CHARACTER_HPP */