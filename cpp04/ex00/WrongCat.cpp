#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat's default constructor is called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat's destructor is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & other)
{
	type = other.type;
	std::cout << "WrongCat's copy constructor is called" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat & animal)
{
	if (this != &animal)
		type = animal.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}