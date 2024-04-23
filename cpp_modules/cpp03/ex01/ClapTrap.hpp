#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    // private become protected for ex01
    protected:
        std::string     name;
        int             hitPoints;
        int             energyPoints;
        int             attackDamage;

    public:
        ClapTrap( /* args */ );
        ClapTrap( std::string newName );
        ClapTrap( const ClapTrap& other );
        ~ClapTrap( void );

        ClapTrap& operator=( const ClapTrap& rightOne );

        // public member functions
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif /* end of CLAPTRAP_HPP */