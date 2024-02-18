#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal *d = new Dog();
    Animal *c = new Cat();
    Animal *a = new Animal();

    std::cout << c->getType() << std::endl;
    std::cout << d->getType() << std::endl;
    std::cout << a->getType() << std::endl;
    c->makeSound();
    d->makeSound();
    a->makeSound();

    {
        std::cout << "*****Innerscope*****" << std::endl;
        Animal *x = new Cat();
        Animal *y = new Cat((const Cat&)*x);
        delete x;
        delete y;
        std::cout << "*****Innerscope*****" << std::endl;
    }

    // we have to add some wrong animall stuff here

    {
        std::cout << "*****Innerscope for WrongAnimal*****" << std::endl;
        WrongAnimal *x = new WrongAnimal();
        WrongAnimal *y = new WrongCat();
        std::cout << x->getType() << std::endl;
        std::cout << y->getType() << std::endl;
        x->makeSound();
        y->makeSound(); // ir will print the same thing with the WrongAnimal
        delete x;
        delete y;
        std::cout << "*****Innerscope for WrongAnimal*****" << std::endl;
    }

    delete a;
    delete c;
    delete d;
    return (0);
}