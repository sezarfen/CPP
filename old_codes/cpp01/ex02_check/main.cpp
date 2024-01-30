#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Memory adress of string variable is : " << &str << std::endl;
	std::cout << "Memory adress held by stringPTR is : " << stringPTR << std::endl;
	std::cout << "Memory adress held by stringREF is : " << &stringREF << std::endl;
}