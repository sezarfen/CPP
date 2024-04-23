#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap c1;
    ClapTrap c2("ClapTrapWithName");
    ClapTrap c3(c2);
    c3 = c1;

    c3.attack("Enemy 0");
    c2.attack("Enemy 1");
    c2.beRepaired(5);
    c2.beRepaired(5);

    // Current Energy points are 7, lets do more moves
    c2.attack("Someone");
    c2.attack("Someone");
    c2.attack("Someone");
    c2.beRepaired(5);
    c2.beRepaired(5);
    c2.beRepaired(5);
    c2.beRepaired(5);
    std::cout << "************* We spent all of our energy points *************" << std::endl;
    c2.beRepaired(5);
    c2.beRepaired(5);
    c2.beRepaired(5);
    c2.attack("Someone");
    c2.attack("Someone");

    return 0;
}
