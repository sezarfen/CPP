#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat( void );
        Cat( const Cat& Cat );
        ~Cat( void );

        Cat& operator=( const Cat& rightOne );

        void makeSound( void ) override; // using override keyword is a great approach, prevent us to do some mistakes, even though while writing the name of the function
};

#endif /* end of CAT_HPP */