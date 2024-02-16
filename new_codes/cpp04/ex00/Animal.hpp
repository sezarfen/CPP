#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;

    public:
        Animal( void );
        Animal( const Animal& other );
        ~Animal( void );

        Animal& operator=( const Animal& rightOne );
};

#endif /* end of ANIMAL_HPP */