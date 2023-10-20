//
// Created by TR on 20.10.2023.
//

#ifndef CPP03_CLAPTRAP_HPP
#define CPP03_CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
private:
    std::string name;
    int hitPoints; // represents the health of the ClapTrap
    int energyPoints;
    int attackDamage;
public:
    // CONSTRUCTORS AND DESTRUCTOR
    ClapTrap( void );
    ClapTrap( std::string name );
    ClapTrap (const ClapTrap & clapTrap);
    ClapTrap & operator = ( const ClapTrap & clapTrap );
    ~ClapTrap( void );

    //  PUBLIC MEMBER FUNCTIONS
    void attack( const std::string& target );
    void takeDamage( unsigned int amount );
    void beRepaired( unsigned int amount );

    // NON-PDF useful functions
    void printInfo( void );
};


#endif //CPP03_CLAPTRAP_HPP
