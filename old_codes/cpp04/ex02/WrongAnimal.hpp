#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal(/* args */);
		WrongAnimal(const WrongAnimal & other);
		~WrongAnimal();
		WrongAnimal & operator = (const WrongAnimal & other);

		std::string getType() const;
		void makeSound() const; // if we delete virtual, that will be wrong
};

#endif /* end of WRONGANIMAL */