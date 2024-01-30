#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	std::cout << "Generating Zombie and using announce() function, with name zm" << std::endl;
	Zombie zombie("zm");
	zombie.announce();

	std::cout << "Generating Zombie from newZombie(name), with name ZM, then delete it" << std::endl;
	Zombie *zm;
	zm = newZombie("ZM");
	std::cout << "Calling announce()" << std::endl;
	zm->announce();
	delete zm; // It will cause a memory leak if not used

	std::cout << "Callning randomChump(name) function, with name ZOMBIE" << std::endl;
	randomChump("ZOMBIE");

	return (0);
}