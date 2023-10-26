#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat's default constructor is called" << std::endl;
	this->brain = new Brain();
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat's destructor is called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat & other)
{
	type = other.type;
	std::cout << "Cat's copy constructor is called" << std::endl;
}

Cat & Cat::operator=(const Cat & animal)
{
	if (this != &animal)
		type = animal.type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}