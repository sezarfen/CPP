#include "Harl.hpp"

int main( int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "It is more healthy to use ./harlFilter [level]" << std::endl;
        return (1);
    }
    Harl h;
    std::string level(argv[1]);
    h.complain(level);
    return (0);
}