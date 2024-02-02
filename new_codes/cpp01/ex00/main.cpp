#include "Zombie.hpp"

Zombie *newZombie( std::string name )
{
    Zombie *zombie = new Zombie(name); // Zombie zombie; return (&zombie); diyip return etsek bile, scope dışında olduğumuz için, objeyi kaybedecektik
    return (zombie); // Zombie &newZombie olsa // return (zombie); diyebiliriz direkt olarak
}

void randomChump( std::string name )
{
    Zombie zombie(name);
    zombie.announce();
}


int main(int argc, char *argv[])
{
    Zombie *z1 = newZombie("Zombie1");
    z1->announce();
    randomChump("Zombie2");
    randomChump("Zombie3");
    randomChump("Zombie4");
    Zombie *z5 = newZombie("Zombie5");
    z5->announce();

    delete z1; // we have to destroy them manually, because they initialized in the heap by using new keyword
    delete z5;
    return (EXIT_SUCCESS);
}