#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixedPoint;

    public:
        Fixed();
        Fixed(const Fixed& fixed);
        ~Fixed();
        Fixed& operator=(const Fixed& fixed);

        static const int fractionalBits = 8;

        int getRawBits( void );
        void setRawBits( int const raw );

        // after ex01
        Fixed(const int number);
        Fixed(const float number);
        float toFloat( void ) const;
        int toInt( void ) const;

        // will continue std::ostream

};

#endif /* end of FIXED_HPP */