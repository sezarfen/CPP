#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    this->type = other.type;
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=( const WrongCat& rightOne )
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this == &rightOne)
        return (*this);
    this->type = rightOne.type;
    return (*this);
}

void WrongCat::makeSound( void )
{
    // even though we explicitly define a sound, it won't gonna use it
    std::cout << "Meowww..." << std::endl;
}