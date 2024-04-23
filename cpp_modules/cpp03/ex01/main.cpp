#include "ScavTrap.hpp"

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
    c2.attack("Someone");
    c2.attack("Someone");
    std::cout << "*************************************************************" << std::endl;
    std::cout << "****************Ex01 New Tests*******************" << std::endl;

    ScavTrap st1;
    ScavTrap st2("ScavTrapWithName");
    ScavTrap st3(st2);
    ScavTrap s4 = st1;

    std::cout << "***Message for inner functions***" << std::endl;
    st2.guardGate();
    st2.attack("Enemy1");
    st3.attack("Enemy3");
    std::cout << "**************************" << std::endl;

    return 0;
}
