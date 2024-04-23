#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal( const WrongAnimal &other )
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    this->type = other.type;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &rightOne )
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    
    if (this == &rightOne)
        return (*this);
    this->type = rightOne.type;
    return (*this);
}

void WrongAnimal::makeSound(void)
{
    // It is not virtual.
    std::cout << "Aww.. JEEE, RRR..., I don't know how does it sounds like" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    std::cout << "Type getter function called" << std::endl;
    return (this->type);
}