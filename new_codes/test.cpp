#include <iostream>


/*
// This cpp file is to test "new" keyword, and scope.

class A
{
public:
    int a;
    int b;
    A();
    A(int a, int b);
    ~A();
};

A::A() : a(3), b(5)
{
}

A::A(int a, int b) : a(a), b(b)
{
}

A::~A()
{
}


A *getAnyA(int av, int bv) // to generate the value in the heap, and not to lose after scope, use new keyword
{
    A *a = new A(av, bv);
    std::cout << "value of the a : " << a->a << std::endl;
    std::cout << "value of the b : " << a->b << std::endl;
    return (a);
}

int main()
{
    A *a = getAnyA(1, 3);
    std::cout << "value of the a : " << a->a << std::endl;
    std::cout << "value of the b : " << a->b << std::endl;

    // if we won't say delete a; it will cause a 8 byte (4 + 4) leak coming from A class
    delete a;
    return (EXIT_SUCCESS);
}
*/

#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 3)
        return (std::cout << "Please use this format ./a.out [file to read] [file to write]" << std::endl, 1);

    std::ofstream fileToWrite;
    std::ifstream fileToRead;
    std::string temp;

    fileToRead.open(argv[1]);
    fileToWrite.open(argv[2]);
    
    while (fileToRead >> temp && fileToWrite << temp);

    return (0);
}