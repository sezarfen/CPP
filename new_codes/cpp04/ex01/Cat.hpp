#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *brain;

    public:
        Cat( void );
        Cat( const Cat& Cat );
        ~Cat( void );

        Cat& operator=( const Cat& rightOne );

        // using override keyword is a great approach, prevent us to do some mistakes, even though while writing the name of the function
        // but it comes after -std=c++11
        void makeSound( void );
};

#endif /* end of CAT_HPP */