#include "Cat.hpp"

Cat::Cat( void )
{
    std::cout << "Cat class's default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat( const Cat& other ) : Animal(other)
{
    std::cout << "Cat class's copy constructor called" << std::endl;
    this->type = other.type;
}

Cat::~Cat( void )
{
    std::cout << "Cat class's destructor called" << std::endl;
}

Cat& Cat::operator=( const Cat& rightOne )
{
    std::cout << "Cat class's copy assignment operator called" << std::endl;
    if (this == &rightOne)
        return (*this);
    this->type = rightOne.type;
    return (*this);
}

void Cat::makeSound( void )
{
    std::cout << "Meowww" << std::endl;
}