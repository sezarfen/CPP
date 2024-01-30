#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define floatToFixed(x) (x * (1 << _fractionalBits)) // float to int
# define fixedToFloat(x) (x / (1 << _fractionalBits)) // int to float

class Fixed
{
	private:
		int					_fixedPointNumber;
		static const int	_fractionalBits;
	public:
		// CONSTRUCTORS
		Fixed ( void );
		Fixed ( const Fixed & fixed );
		Fixed ( const int number );
		Fixed ( const float number );

		// OPERATOR OVERLOADS
		Fixed & operator = ( const Fixed & fixed );

		// MEMBER FUNCTIONS
		int getRawBits ( void ) const;
		void setRawBits ( int const raw );
		float toFloat( void ) const;
		int toInt ( void ) const;

		// DESTRUCTOR
		~Fixed( void );
};

std::ostream & operator<<(std::ostream &out, Fixed &fixed);

#endif /* end of FIXED_HPP */