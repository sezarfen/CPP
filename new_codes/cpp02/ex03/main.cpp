#include "Fixed.hpp"

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "---------My own examples---------" << std::endl;
    Fixed c(15);
    Fixed d(2);

    std::cout << "Division check: " << c / d << std::endl;
    std::cout << "Subtraction check : " << c - d << std::endl;
    std::cout << "Multiplication check : " << c * d << std::endl;
    std::cout << "Addition check : " << c + d << std::endl;
    std::cout << "---------------------------------" << std::endl;

    return 0;
}