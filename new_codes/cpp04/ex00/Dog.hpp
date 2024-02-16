#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>

class Dog
{

    public:
        Dog( void );
        Dog( const Dog& dog );
        ~Dog( void );

        Dog& operator=( const Dog& rightOne );
};

#endif /* end of DOG_HPP */