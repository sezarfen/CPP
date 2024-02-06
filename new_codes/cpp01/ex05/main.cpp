#include "Harl.hpp"

int main( void )
{
    Harl h;

    std::cout << "Calling Harl on DEBUG mode" << std::endl;
    h.complain("DEBUG");
    std::cout << "*********************************" << std::endl;
    
    std::cout << "Calling Harl on INFO mode" << std::endl;
    h.complain("INFO");
    std::cout << "*********************************" << std::endl;

    std::cout << "Calling Harl on WARNING mode" << std::endl;
    h.complain("WARNING");
    std::cout << "*********************************" << std::endl;

    std::cout << "Calling Harl on ERROR mode" << std::endl;
    h.complain("ERROR");
    std::cout << "*********************************" << std::endl;
    
    std::cout << "Calling Harl with something else" << std::endl;
    h.complain("ELSE");
    return (0);
}