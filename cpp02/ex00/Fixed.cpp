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

// OPERATOR OVERLOADS

Fixed & Fixed::operator= ( const Fixed & fixed ) // it returns the instance (I guess)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		//setRawBits(fixed.getRawBits());
		this->_fixedPointNumber = fixed.getRawBits();
	return (*this);
}

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

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}