#include "Harl.hpp"

void Harl::complain( std::string level )
{
	std::string	functionNames[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void 	(Harl::*functionsTable[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(functionNames[i]) == 0)
			(this->*functionsTable[i])();
	}
}

void Harl::debug()
{
	std::cout << "I love having bigger Ayran in my Doner-Ayran Menu, I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding bigger Ayran costs more money, 150ml not enough for this menu!!!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have bigger Ayran for free, I've been coming for years whereas you started working here since the last month!" << std::endl;
}

void Harl::error()
{
	std::cout << "This unacceptable! I want to speak to the manager now." << std::endl;
}
