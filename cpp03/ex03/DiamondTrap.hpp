#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap(std::string name);
        using FragTrap::hitPoints;
        using ScavTrap::energyPoints;
        using FragTrap::attackDamage;
        
        using ScavTrap::attack;
        void whoAmI( void );
        
};

# endif /* end of DIAMONDTRAP_HPP */