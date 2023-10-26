#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(/* args */);
		~Cat();
		Cat(const Cat & other);
		Cat & operator = (const Cat & other);

		void makeSound() const;
};

#endif /* end of CAT_HPP */