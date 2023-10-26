#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/*
You create an abstract class by declaring
at least one pure virtual member function.
That's a virtual function declared by using
the pure specifier (= 0) syntax. Classes derived
from the abstract class must implement the pure
virtual function or they, too, are abstract classes.
*/

class Animal
{
	protected:
		std::string type;
	public:
		Animal( void );
		Animal(const Animal & other);
		virtual ~Animal();      // used virtual keyword to use Cat's and Dog's destructors
		Animal & operator = (const Animal & animal);

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif /* end of ANIMAL_HPP */