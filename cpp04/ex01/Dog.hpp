#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog(/* args */);
		~Dog();
		Dog(const Dog & other);
		Dog & operator = (const Dog & other);

		void makeSound() const;
};

#endif /* end of DOG_HPP */