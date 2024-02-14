#include "Point.hpp"

Point::Point( void ) : x(Fixed(0)), y(Fixed(0))
{
}

Point::Point( float x , float y ) : x(Fixed(x)) , y (Fixed(y))
{
}

Point::Point( const Point& point ) : x(point.x) , y(point.y)
{
}

Point& Point::operator=(const Point& point)
{
    (void)point; // x and y are const, does not make sense to change it
    return (*this);
}

const Fixed& Point::getX() const
{
    return (this->x);
}

const Fixed& Point::getY() const
{
    return (this->y);
}

Point::~Point()
{
    std::cout << "Default destructor called" << std::endl;
}