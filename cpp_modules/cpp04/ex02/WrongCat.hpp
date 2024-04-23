#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat( void );
        WrongCat( const WrongCat& other );
        ~WrongCat( void );

        WrongCat& operator=( const WrongCat& rightOne );

        void makeSound( void );
};

#endif /* end of WRONGCAT_HPP */