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
        virtual ~Animal( void );

        Animal& operator=( const Animal& rightOne );

        virtual void makeSound( void );

        std::string getType( void ) const;
};

#endif /* end of ANIMAL_HPP */