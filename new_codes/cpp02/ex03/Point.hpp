#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point( void );
        Point( float x, float y );
        Point( const Point& point );

        // Useful functions
        const Fixed& getX() const;
        const Fixed& getY() const;

        Point& operator=(const Point& point);
        ~Point( void );
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif /* end of POINT_HPP */