#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
    Animal *animalArray = new Animal[50];
    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            animalArray[i] = new Dog();
        else
            animalArray[i] = new Cat();
    }
    return (0);
}