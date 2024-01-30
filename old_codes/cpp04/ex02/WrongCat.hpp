#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(/* args */);
		~WrongCat();
		WrongCat(const WrongCat & other);
		WrongCat & operator = (const WrongCat & other);

		void makeSound() const;
};

#endif /* end of WRONGCAT_HPP */