#include "Fixed.hpp"

// CONSTRUCTORS

Fixed::Fixed( void ) : _fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & fixed ) // it just copies the values
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointNumber = fixed.getRawBits();
}

Fixed::Fixed( const int number )
{
	this->_fixedPointNumber = number << this->_fractionalBits;
}

Fixed::Fixed( const float number )
{
	this->_fixedPointNumber = std::roundf(number / (1 << this->_fractionalBits));
}

// OPERATOR OVERLOADS

Fixed & Fixed::operator= ( const Fixed & fixed ) // it returns the instance (I guess)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		//setRawBits(fixed.getRawBits());
		this->_fixedPointNumber = fixed.getRawBits();
	return (*this);
}

// MEMBER FUNCTIONS

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNumber);
}

void Fixed::setRawBits( int const raw  )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNumber = raw;
}

float Fixed::toFloat( void ) const
{
	return this->_fixedPointNumber / (1 << this->_fractionalBits);
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPointNumber >> _fractionalBits);	
}

// DESTRUCTOR

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

// OSTREAM OVERLOAD

std::ostream & operator<<(std::ostream &out, Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}