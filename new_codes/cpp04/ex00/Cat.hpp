#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>

class Cat
{

    public:
        Cat( void );
        Cat( const Cat& Cat );
        ~Cat( void );

        Cat& operator=( const Cat& rightOne );
};

#endif /* end of CAT_HPP */