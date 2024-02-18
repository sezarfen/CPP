#include "Cat.hpp"

Cat::Cat( void )
{
    std::cout << "Cat class's default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat( const Cat& other ) : Animal(other)
{
    std::cout << "Cat class's copy constructor called" << std::endl;
    this->type = other.type;
    this->brain = other.brain;
}

Cat::~Cat( void )
{
    std::cout << "Cat class's destructor called" << std::endl;
    delete brain;
}

Cat& Cat::operator=( const Cat& rightOne )
{
    std::cout << "Cat class's copy assignment operator called" << std::endl;
    if (this == &rightOne)
        return (*this);
    this->type = rightOne.type;
    delete brain; // otherwise it might cause a memory leak.
    this->brain = rightOne.brain;
    return (*this);
}

void Cat::makeSound( void )
{
    std::cout << "Meowww" << std::endl;
}