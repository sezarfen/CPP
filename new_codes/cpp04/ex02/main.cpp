#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;

    Animal **animalArray = new Animal*[10];
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            animalArray[i] = new Dog();
        else
            animalArray[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
        delete animalArray[i];
    delete[] animalArray;

    // New Tests for ex02
    Animal *a = new Animal();
    a->getType();

    return (0);
}