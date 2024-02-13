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
        Fixed getX() const;
        Fixed getY() const;

        Point& operator=(const Point& point);
        ~Point( void );
};

#endif /* end of POINT_HPP */