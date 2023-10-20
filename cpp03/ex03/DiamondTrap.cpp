#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
: ClapTrap::ClapTrap(name + "_clap_name") , _name(name)  // we add virtual keyword to Trap classes inheritances
{

}

void DiamondTrap::whoAmI( void )
{
    std::cout << "DiamondTrap name is " << this->_name << std::endl;
    std::cout << "DiamondTrap's ClapTrap name is " << ClapTrap::_name << std::endl;
}