#include "Animal.hpp"

Animal::Animal( void )
{
    std::cout << "Animal class's default constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal( const Animal& other )
{
    std::cout << "Animal class's copy constructor called" << std::endl;
    this->type = other.type;
}

Animal::~Animal( void )
{
    std::cout << "Animal class's destructor called" << std::endl;
}

Animal& Animal::operator=( const Animal& rightOne )
{
    std::cout << "Animal class's copy assignment operator called" << std::endl;
    if (this == &rightOne)
        return (*this);
    this->type = rightOne.type;
    return (*this);
}

void Animal::makeSound( void )
{
    std::cout << "Tell me which sound I made, I don't know my exact type yet" << std::endl;
}

std::string Animal::getType( void ) const
{
    std::cout << "type getter function called" << std::endl;
    return (this->type);
}