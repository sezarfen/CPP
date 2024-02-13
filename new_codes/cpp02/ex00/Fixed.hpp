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

        int getRawBits( void ) const;
        void setRawBits( int const raw );

};

#endif /* end of FIXED_HPP */