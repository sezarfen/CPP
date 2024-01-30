#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(/* args */);
		~Dog();
		Dog(const Dog & other);
		Dog & operator = (const Dog & other);

		void makeSound() const;
};

#endif /* end of DOG_HPP */