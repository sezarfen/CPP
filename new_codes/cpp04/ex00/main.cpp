#include "Dog.hpp"
#include "Cat.hpp"

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

    delete a;
    delete c;
    delete d;
    return (0);
}