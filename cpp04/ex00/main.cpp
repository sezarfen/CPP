# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();

	const WrongAnimal * meta1 = new WrongAnimal();
	const WrongAnimal * cat1 = new WrongCat();

	std::cout << meta1->getType() << " " << std::endl;
	std::cout << cat1->getType() << " " << std::endl;
	meta1->makeSound();
	cat1->makeSound();

	return (0);
}