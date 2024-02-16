#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap( void );
        FragTrap( const FragTrap& other );
        FragTrap( const std::string name );
        ~FragTrap( void );

        FragTrap& operator=( const FragTrap& rightOne );

        void highFivesGuys( void );
};

#endif /* end of FRAGTRAP_HPP */