#include "Zombie.hpp"
Zombie	*zombieHorde(int N, std::string name);

void announceZombies(Zombie *zombies, int n)
{
	for (int i = 0; i < n; i++)
		zombies[i].announce();
}

int main()
{
	// NO SENSE NUMBER OF ZOMBIES

	std::cout << "Try to generate -5 zombies with name zm" << std::endl;
	Zombie *zombies1 = zombieHorde(-5, "zm");
	if (!zombies1)
		std::cout << "Cannot generate zombies" << std::endl;
	else
		announceZombies(zombies1, -5);
	std::cout << "*******************" << std::endl;

	std::cout << "Try to generate 0 zombies with name ZM" << std::endl;
	Zombie *zombies2 = zombieHorde(0, "ZM");
	if (!zombies2)
		std::cout << "Cannot generate zombies" << std::endl;
	else
		announceZombies(zombies2, 0);
	std::cout << "*******************" << std::endl;

	// POZITIVE INTEGER NUMBER OF ZOMBIES

	std::cout << "Try to generate 3 zombies with name Zombiee3" << std::endl;
	Zombie *zombies3 = zombieHorde(3, "Zombiee3");
	if (!zombies3)
		std::cout << "Cannot generate zombies" << std::endl;
	else
		announceZombies(zombies3, 3);
	std::cout << "*******************" << std::endl;

	std::cout << "Try to generate 7 zombies with name Zombiee7" << std::endl;
	Zombie *zombies7 = zombieHorde(7, "Zombiee7");
	if (!zombies7)
		std::cout << "Cannot generate zombies" << std::endl;
	else
		announceZombies(zombies7, 7);
	std::cout << "*******************" << std::endl;

	return (0);
}