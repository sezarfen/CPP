#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "Brain class default constructor called" << std::endl;
}

Brain::Brain( const Brain& other )
{
    std::cout << "Brain class copy constructor called" << std::endl;
    
    // just copying the contents // I think it counts as a deep copy
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain::~Brain( void )
{
    std::cout << "Brain class destructor called" << std::endl;
}

Brain& Brain::operator=( const Brain& rightOne )
{
    if (this == &rightOne)
        return (*this);

    // just copying the contents // I think it counts as deep copy
    for (int i = 0; i < 100; i++)
        this->ideas[i] = rightOne.ideas[i];
    
    return (*this);
}