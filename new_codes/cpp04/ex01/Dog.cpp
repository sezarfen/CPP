#include "Dog.hpp"

Dog::Dog( void )
{
    std::cout << "Dog class's default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog( const Dog& other ) : Animal(other)
{
    std::cout << "Dog class's copy constructor called" << std::endl;
    this->type = other.type;
    this->brain = other.brain;
}

Dog::~Dog( void )
{
    std::cout << "Dog class's destructor called" << std::endl;
    delete brain;
}

Dog& Dog::operator=( const Dog& rightOne )
{
    std::cout << "Dog class's copy assignment operator called" << std::endl;
    if (this == &rightOne)
        return (*this);
    this->type = rightOne.type;
    delete brain;
    this->brain = rightOne.brain;
    return (*this);
}

void Dog::makeSound( void )
{
    std::cout << "Hav hav hav" << std::endl;
}