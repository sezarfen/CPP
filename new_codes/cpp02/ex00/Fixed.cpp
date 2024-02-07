#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Fixed class default constructor" << std::endl; 
}

Fixed::Fixed(const Fixed& other)
{
    // copy the instructions to other class to our class
}

Fixed::~Fixed()
{
    std::cout << "Fixed class default destructor" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed)
{
    
}