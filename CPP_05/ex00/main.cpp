#include "Bureaucrat.hpp"

int main(int argc, char **argv, char **env){
    
    try{
        Bureaucrat bur(5);
        bur.incrementGrade(3);
        std::cout << bur << std::endl;
    }catch(const std::exception& exc){
        std::cout << exc.what() << std::endl; 
    }

    try{
        Bureaucrat bur("Bro"); // default grade 150
        bur.decrementGrade(3);
    }catch(const std::exception& exc){
        std::cout << exc.what() << std::endl;
    }

    try{
        Bureaucrat bur("Bro", 1);
        bur.incrementGrade(5);
    }catch(const std::exception& exc){
        std::cout << exc.what() << std::endl;
    }

    try{
        Bureaucrat bur("Bro", 149);
        bur.decrementGrade(5);
    }catch(const std::exception& exc){
        std::cout << exc.what() << std::endl;
    }

    try{
        Bureaucrat bur("Bro", 500);
        std::cout << "Hello World Test!!!" << std::endl;
    }catch(const std::exception& exc){
        std::cout << exc.what() << std::endl;
    }

    try{
        Bureaucrat bur("Bro", 15);
        Bureaucrat buro2(bur);
        buro2.incrementGrade(25);
        std::cout << "Hi World?" << std::endl;
    }catch(const std::exception& exc){
        std::cout << exc.what() << std::endl;
    }

    return (0);
}
