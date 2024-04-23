#include "Dog.hpp"

Dog::Dog( void )
{
    std::cout << "Dog class's default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog( const Dog& other ) : Animal(other)
{
    std::cout << "Dog class's copy constructor called" << std::endl;
    this->type = other.type;
}

Dog::~Dog( void )
{
    std::cout << "Dog class's destructor called" << std::endl;
}

Dog& Dog::operator=( const Dog& rightOne )
{
    std::cout << "Dog class's copy assignment operator called" << std::endl;
    if (this == &rightOne)
        return (*this);
    this->type = rightOne.type;
    return (*this);
}

void Dog::makeSound( void )
{
    std::cout << "Hav hav hav" << std::endl;
}