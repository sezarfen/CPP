#include <iostream>
class deneme{
    public:
        int x;
        std::string name;
        deneme(std::string name) : name(name)
        {
            x = 42;
            std::cout << "constructor called" << std::endl;
        }

        deneme(const deneme&obj)
        {
            this->x = obj.x + 1;
            std::cout << "copy constructor called\n";
        }

        deneme& operator=(const deneme& obj)
        {
            this->x = obj.x;
            std::cout << "my name is : " << this->name << std::endl;
            std::cout << "copy assignment called\n";
            return(*this);
        }

        ~deneme()
        {
            std::cout << "destructor called\n";
        }
};
int main()
{
    deneme obj1("obj1");
}