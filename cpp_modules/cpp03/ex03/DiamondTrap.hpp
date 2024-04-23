#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap 
{
    private:
        std::string name;
    
    public:
        DiamondTrap( void );
        DiamondTrap( const DiamondTrap& other );
        DiamondTrap( std::string name );
        ~DiamondTrap( void );

        DiamondTrap& operator=( const DiamondTrap& rightOne );

        void attack( std::string enemy );
        
        void whoAmI( void );
};

#endif /* end of DIAMONDTRAP_HPP */