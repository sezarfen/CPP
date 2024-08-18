#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150) {
    std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat( void ){
    std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other._name), _grade(other._grade){
    std::cout << "Copy constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat( int grade ) : _name("default"), _grade(grade){
    if (grade < 1){
        throw GradeTooHighException();
    }
    else if (grade > 150){
        throw GradeTooLowException();
    }
    std::cout << "Only using int constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name ) : _name(name), _grade(150){
    std::cout << "Only using string constructor is called" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade){
    if (grade < 1){
        throw GradeTooHighException();
    }
    else if (grade > 150){
        throw GradeTooLowException();
    }
    std::cout << "2 parameters constructor is called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& rhs ){
    // since rhs is also implied same rules before, not going to check _grade
    if (this == &rhs){
        return (*this);
    }
    this->_grade = rhs._grade;
    return (*this);
}

std::string Bureaucrat::getName( void ) const {
    return (this->_name);
}

int Bureaucrat::getGrade( void ) const {
    return (this->_grade);
}

const char * Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade Too High";
}

const char * Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade Too Low";
}

std::ostream	&operator<<(std::ostream &ost, const Bureaucrat& bur){
    ost << bur.getName() << ", bureaucrat grade " << bur.getGrade() << ".";
    return ost;
}

void Bureaucrat::incrementGrade( int amount ){
    if (this->_grade - (amount - 1) < 1){
        throw GradeTooHighException();
    }
    this->_grade -= (amount - 1);
}

void Bureaucrat::decrementGrade( int amount ){
    if (this->_grade + (amount - 1) > 150){
        throw GradeTooLowException();
    }
    this->_grade += (amount - 1);
}