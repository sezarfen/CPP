#include "Zombie.hpp"

Zombie::Zombie( void ){}

Zombie::Zombie( std::string name ) : name(name) {}

Zombie::~Zombie( void )
{
    std::cout << "Zombie named " << this->name << " destroyed" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName( std::string name )
{
    this->name = name;
}