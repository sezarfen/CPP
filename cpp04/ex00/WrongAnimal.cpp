#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal's Default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal's destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & other)
{
	type = other.type;
	std::cout << "WrongAnimal's copy constructor is called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & animal)
{
	if (this != &animal)
		type = animal.type;
	return (*this);
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Which animal is this? whatever, Auuuuuu..." << std::endl;
}