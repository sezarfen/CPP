#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog's default constructor is called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog's destructor is called" << std::endl;
}

Dog::Dog(const Dog & other)
{
	type = other.type;
	std::cout << "Dog's copy constructor is called" << std::endl;
}

Dog & Dog::operator=(const Dog & animal)
{
	if (this != &animal)
		type = animal.type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Hauv Hauv" << std::endl;
}