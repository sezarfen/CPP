#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain class default constructor called" << std::endl;
}

Brain::Brain( const Brain& other )
{
    std::cout << "Brain class copy constructor called" << std::endl;
    this->ideas = other.ideas;
}

Brain::~Brain( void )
{
    std::cout << "Brain class destructor called" << std::endl;
}

Brain::operator=( const Brain& rightOne )
{
    if (this == &rightOne)
        return (*this);
    this->ideas = rightOne.ideas;
    return (*this);
}