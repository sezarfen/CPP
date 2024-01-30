#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixedPointNumber;
		static const int	_fractionalBits;
	public:
		// CONSTRUCTORS
		Fixed ( void );
		Fixed ( const Fixed & fixed );

		// OPERATOR OVERLOADS
		Fixed & operator = (const Fixed & fixed);

		// MEMBER FUNCTIONS
		int getRawBits ( void ) const;
		void setRawBits ( int const raw );

		// DESTRUCTOR
		~Fixed( void );
};

#endif /* end of FIXED_HPP */