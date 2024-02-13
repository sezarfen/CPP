#include <iostream>
#include <cmath>
#include <iomanip>

class Fixed
{
    private:
        int number; // something like integer, could be any value like = 5, but when we use the float number such as someone give us = 42.42, I think we should shift to the right for both cases << this->dotLength
        const int dotLength = 8;
    public:
        Fixed(const int number);
        Fixed(const float number);

        
        int toInt( void ) const;
        float toFloat( void ) const;
};

Fixed::Fixed(const int number)
{
    this->number = number << this->dotLength;
}

Fixed::Fixed(const float number)
{
    float newNum = number;
    for (int i = 0; i < this->dotLength; i++)
        newNum *= 2;
    this->number = (int)newNum;
}

int Fixed::toInt( void ) const
{  

}



int main()
{
    Fixed f(42.42f);
    std::cout << f.getNumber() << std::endl;
    return (0);
}