#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog( void );
        Dog( const Dog& dog );
        ~Dog( void );

        Dog& operator=( const Dog& rightOne );

        void makeSound( void ) override;
};

#endif /* end of DOG_HPP */