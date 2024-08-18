#include "Form.hpp"

Form::Form( void ) : 
_name("default"),
_isSigned(false),
_gradeNeededToSign(5),
_gradeNeededToExecute(5)
{
}

Form::Form( std::string name, int gradeNeededToSign, int gradeNeededToExecute ) :
_name(name),
_isSigned(false),
_gradeNeededToSign(gradeNeededToSign),
_gradeNeededToExecute(gradeNeededToExecute)
{
    if (_gradeNeededToExecute > 150)
        throw Form::GradeTooLowException();
    else if (_gradeNeededToExecute < 1)
        throw Form::GradeTooHighException();
    else if (_gradeNeededToSign > 150)
        throw Form::GradeTooLowException();
    else if (_gradeNeededToSign < 1)
        throw Form::GradeTooHighException();
}

Form::~Form(){}

Form::Form( const Form& other ) :
_name(other._name),
_isSigned(other._isSigned),
_gradeNeededToSign(other._gradeNeededToSign),
_gradeNeededToExecute(other._gradeNeededToExecute)
{

}

Form& Form::operator=( const Form& rhs ){
    if (this == &rhs){
        return (*this);
    }
    this->_isSigned = rhs._isSigned;
    return (*this);
}

const std::string Form::getName( void ) const{
    return this->_name;
}

bool Form::getIsSigned( void ) const{
    return this->_isSigned;
}

const int Form::getGradeNeededToSign( void ) const{
    return this->_gradeNeededToSign;
}

const int Form::getGradeNeededToExecute( void ) const{
    return this->_gradeNeededToExecute;
}

void Form::beSigned( Bureaucrat& bureaucrat ){
    int grade = bureaucrat.getGrade();
    if (grade > this->_gradeNeededToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

const char * Form::GradeTooHighException::what() const throw(){
    return "Grade Too High";
}

const char * Form::GradeTooLowException::what() const throw(){
    return "Grade Too Low";
}

std::ostream	&operator<<(std::ostream &ost, const Form& form){
    ost << "name: " << form.getName() << ", isSigned: " << form.getIsSigned() << ", gradeNeededToSign: " << form.getGradeNeededToSign() << ", gradeNeededToExecute: " << form.getGradeNeededToExecute();
    return ost;
}