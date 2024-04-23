#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal( void );
    WrongAnimal( const WrongAnimal& other );
    ~WrongAnimal();

    WrongAnimal& operator=( const WrongAnimal& rightOne );

    // lets not set this one as a virtual
    void makeSound( void );

    std::string getType( void ) const;
};

#endif /* end of WRONGANIMAL_HPP */