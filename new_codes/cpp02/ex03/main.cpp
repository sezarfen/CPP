#include "Point.hpp"

int main( void ) 
{
    Point p1(0, 5);
    Point p2(3, 0);
    Point p3(-3, -3);

    Point myPoint(-1, 0);

    if (bsp(p1, p2, p3, myPoint))
        std::cout << "Your point inside of the triangle" << std::endl;
    else
        std::cout << "Your point outside of the triangle" << std::endl;

    return 0;
}