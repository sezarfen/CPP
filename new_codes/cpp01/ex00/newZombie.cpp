#include "Zombie.hpp"

Zombie *newZombie( std::string name )
{
    Zombie *zombie = new Zombie(name); // Zombie zombie; return (&zombie); diyip return etsek bile, scope dışında olduğumuz için, objeyi kaybedecektik
    return (zombie); // Zombie &newZombie olsa // return (zombie); diyebiliriz direkt olarak
}