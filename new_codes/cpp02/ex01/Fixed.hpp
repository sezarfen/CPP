#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
// aftere ex01
#include <cmath>

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

        int getRawBits( void ) const ;
        void setRawBits( int const raw );

        // After ex01
        Fixed(const int number);
        Fixed(const float number);
        float toFloat( void ) const;
        int toInt( void ) const;
};

// to output our class when given to the std::cout << Class
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif /* end of FIXED_HPP */