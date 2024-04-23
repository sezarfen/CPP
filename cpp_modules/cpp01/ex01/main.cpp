#include "Zombie.hpp"

int main( void )
{
    int numberOfZombies = 7;
    Zombie *zombies = zombieHorde(numberOfZombies, "ZZZooommmbbbiiieee");
    for (int i = 0; i < numberOfZombies; i++)
    {
        zombies[i].announce();
    }
    std::cout << "Before deleting all the zombies, quick question : How are you?" << std::endl;
    delete[] zombies; // to delete array of zombies, use delete[]
    return (0);
}