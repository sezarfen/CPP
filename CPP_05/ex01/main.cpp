#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(int argc, char **argv, char **env){

    std::cout << "=========== TEST0 ===========" << std::endl;

    try{
        Bureaucrat bur("Unknown", 15);
        Form form("ImportantPaper", 25, 15);
        std::cout << "is form signed: " << form.getIsSigned() << std::endl;
        bur.signForm(form);
        std::cout << "is form signed: " << form.getIsSigned() << std::endl;
    }
    catch(const std::exception& exc){
        std::cout << exc.what() << std::endl;
    }
    
    std::cout << "=========== TEST1 ===========" << std::endl;

    try{
        Bureaucrat bur("Bro", 135);
        Form form("ReallyImportantPaper1", 13, 13);
        bur.signForm(form);
    }
    catch(const std::exception& exc){
        std::cout << exc.what() << std::endl;
    }

    std::cout << "=========== TEST2 ===========" << std::endl;

    try{
        Form form("ReallyImportantPaper2", 0, -1);
    }
    catch(const std::exception& exc){
        std::cout << exc.what() << std::endl;
    }

    std::cout << "=========== TEST3 ===========" << std::endl;

    try{
        Form form("ReallyImportantPaper3", 150, 155);
    }
    catch(const std::exception& exc){
        std::cout << exc.what() << std::endl;
    }

    return (0);
}
