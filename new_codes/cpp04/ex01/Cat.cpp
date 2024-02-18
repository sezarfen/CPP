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

    // For deep copy, generate a new area in the heap and fill with the values
    if (this->brain)
        delete brain;
    this->brain = new Brain(other.brain); // if we could call this->brain = rightOne.brain this will lead to shallow copy, and it will effect program in undesired way
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

    // For deep copy, generate a new area in the heap and fill with the values
    if (this->brain)
        delete brain;
    this->brain = new Brain(rightOne.brain); // if we could call this->brain = rightOne.brain this will lead to shallow copy, and it will effect program in undesired way
    
    return (*this);
}

void Cat::makeSound( void )
{
    std::cout << "Meowww" << std::endl;
}