#include "Harl.hpp"

/**
 * Comments of Harl:
 * "DEBUG" : "I love having extra tomato sauce for my 7XL-double-cheese-triple-pickle-specialketchup doner. I really do!"
 * "INFO" : "I cannot believe adding extra tomato sauce costs more money. You didn’t put enough sauce in my burger! If you did, I wouldn’t be asking for more!"
 * "WARNING" : "I think I deserve to have some extra sauce for free. I’ve been coming for years whereas you started working here since last month."
 * "ERROR" :  "This is unacceptable! I want to speak to the manager now."
*/

void    Harl::debug( void )
{
    std::cout << "I love having extra tomato sauce for my 7XL-double-cheese-triple-pickle-specialketchup doner. I really do!" << std::endl;
}

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra tomato sauce costs more money. You didn’t put enough sauce in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra sauce for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain( std::string level )
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*f[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int current = -1;
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            current = i;
    }

    if (current < 0)
    {
        std::cout << "This is interesting but Harl don't want to say something for that" << std::endl;
    }
    else
    {
        (this->*f[current])();
    }
}