# include "Animal.hpp"
# include "Dog.hpp"
# include "Cat.hpp"
# include "WrongAnimal.hpp"
# include "WrongCat.hpp"

int main()  // THERE ARE A LOT OF MEMORY LEAKS, I GUESS ANIMALS[I] element's destructor not called
{
	Animal* animals[100];

	for (int i = 0; i < 50; i++)
		animals[i] = new Dog();

	for (int i = 50; i < 100; i++)
		animals[i] = new Cat();

	for (int i = 0; i < 100; i++)
		delete animals[i];

	return (0);
}