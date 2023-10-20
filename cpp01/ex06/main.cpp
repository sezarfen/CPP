#include "Harl.hpp"

int main(int ac, char **av)
{

	// ERROR CHECK
	if (ac != 2)
	{
		std::cout << "Wrong number of arguments given.." << std::endl;
		return (1);
	}

	// VARIABLES THAT WE GONNA USE
	int i;
	Harl harl;
	std::string arg(av[1]);
	std::string levelNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	// LOCATE I TO level's position
	for (i = 0; i < 4; i++)
	{
		if (arg.compare(levelNames[i]) == 0)
			break;
	}

	if (i == 4)
	{
		std::cout << "Harl Not Interested with it." << std::endl;
		return (1);
	}

	// SWITCH-CASE STATEMENT AND ARGUMENT
	std::cout << "[ " << arg << " ]" << std::endl;
	switch (i)
	{
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
	default:
		break;
	}

	return (0);
}