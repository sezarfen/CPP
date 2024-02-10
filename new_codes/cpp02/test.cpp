#include <iostream>

class A
{
    private:
        int a;
        std::string name;
    public:
        A(std::string name)
        {
            this->name = name;
            std::cout << "Default constructor called" << std::endl;
        }

        A& operator=(const A& other)
        {
            std::cout << "My name is : " << this->name << std::endl;
            return (*this);
        }

        A(const A& other)
        {
            this->a = other.a;
        }

        int getA()
        {
            return (this->a);
        }

        void setA(const int newA)
        {
            this->a = newA;
        }
};


int main(int argc, char const *argv[])
{
    A a1("a1");
    A a2("a2");

    a1.setA(123);
    a1 = a2;
    std::cout << a2.getA() << std::endl;
    return (0);
}
