#include "Harl.hpp"

int main()
{
	Harl harl;


	// CALLING DEBUG
	std::cout << "Calling DEBUG from Harl, please don't bother him." << std::endl;
	harl.complain("DEBUG");
	std::cout << "*************************" << std::endl;

	// CALLING INFO
	std::cout << "Calling INFO from Harl, please listen to him for this time." << std::endl;
	harl.complain("INFO");
	std::cout << "*************************" << std::endl;


	// CALLING WARNING
	std::cout << "Calling WARNING from Harl, I'm gonna warn him to, no worries." << std::endl;
	harl.complain("WARNING");
	std::cout << "*************************" << std::endl;

	// CALLING ERROR 
	std::cout << "Calling ERROR from Harl, I don't know whats gonna happen." << std::endl;
	harl.complain("ERROR");
	std::cout << "*************************" << std::endl;

	// CALLING NOTHING (someting not related)
	std::cout << "Calling Something not related with Harl, He do not have any problem with this." << std::endl;
	harl.complain("nothing");
	std::cout << "*************************" << std::endl;

	return (0);
}
