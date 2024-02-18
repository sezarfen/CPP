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
    
    // For deep copy, generate a new area in the heap and fill with the values
    if (this->brain)
        delete brain;
    this->brain = new Brain(other.brain); // if we could call this->brain = rightOne.brain this will lead to shallow copy, and it will effect program in undesired way

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
    
    // For deep copy, generate a new area in the heap and fill with the values
    if (this->brain)
        delete brain;
    this->brain = new Brain(rightOne.brain); // if we could call this->brain = rightOne.brain this will lead to shallow copy, and it will effect program in undesired way

    return (*this);
}

void Dog::makeSound( void )
{
    std::cout << "Hav hav hav" << std::endl;
}