#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal's Default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal's destructor called" << std::endl;
}

Animal::Animal(const Animal & other)
{
	type = other.type;
	std::cout << "Animal's copy constructor is called" << std::endl;
}

Animal & Animal::operator=(const Animal & animal)
{
	if (this != &animal)
		type = animal.type;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Which animal is this? whatever, Auuuuuu..." << std::endl;
}