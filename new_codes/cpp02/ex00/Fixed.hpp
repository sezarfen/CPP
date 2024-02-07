#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:

    public:
        Fixed();
        Fixed(const Fixed& fixed);
        ~Fixed();
        Fixed& operator=(const Fixed& fixed);

};

#endif /* end of FIXED_HPP */