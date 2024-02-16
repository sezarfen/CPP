#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap( /* args */ );
        ScavTrap( std::string newName );
        ScavTrap( const ScavTrap& other );
        ~ScavTrap( void );
        ScavTrap& operator=( const ScavTrap& rightOne );

        void guardGate( void );

};

#endif /* end of SCAVTRAP_HPP */