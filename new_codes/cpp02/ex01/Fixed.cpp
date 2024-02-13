#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    
    // this->operator=(other); // If I use this and let the bottom one as a comment, it will be same as subject
    this->setRawBits(other.fixedPoint);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& right) // a1 = a2, right indicates a2
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this == &right) // if they do something like "a1 = a1", this statement becomes true, we don't have to copy something, it is what it is already
        return (*this);
    
    // because on the subject we saw the getRawBits message while copy assignment call made
    this->setRawBits(right.fixedPoint);
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPoint);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "getRawBits member function called" << std::endl;
}

// After ex01

Fixed::Fixed(const int number)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixedPoint = number << this->fractionalBits;
}

Fixed::Fixed(const float number)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPoint = (int)roundf(number * pow(2, this->fractionalBits));
}

float Fixed::toFloat( void ) const
{
    return ((float)this->fixedPoint / (1 << this->fractionalBits));
}

int Fixed::toInt( void ) const
{
    return (this->fixedPoint >> this->fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}