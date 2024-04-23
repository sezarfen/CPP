#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

// to make class a abstract, there must be at least 1 pure virtual member function
// We can also make name for the class Animal, AAnimal
class Animal
{
    protected:
        std::string type;

    public:
        Animal( void );
        Animal( const Animal& other );
        virtual ~Animal( void );

        Animal& operator=( const Animal& rightOne );

        virtual void makeSound( void ) = 0;

        std::string getType( void ) const;
};

#endif /* end of ANIMAL_HPP */