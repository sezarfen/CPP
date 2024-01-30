#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

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
		virtual void makeSound() const;
};

#endif /* end of ANIMAL_HPP */