#include "AForm.hpp"

AForm::AForm( void ) : 
_name("default"),
_isSigned(false),
_gradeNeededToSign(5),
_gradeNeededToExecute(5)
{
}

AForm::AForm( std::string name, int gradeNeededToSign, int gradeNeededToExecute ) :
_name(name),
_isSigned(false),
_gradeNeededToSign(gradeNeededToSign),
_gradeNeededToExecute(gradeNeededToExecute)
{
    if (_gradeNeededToExecute > 150)
        throw AForm::GradeTooLowException();
    else if (_gradeNeededToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (_gradeNeededToSign > 150)
        throw AForm::GradeTooLowException();
    else if (_gradeNeededToSign < 1)
        throw AForm::GradeTooHighException();
}

AForm::~AForm(){}

AForm::AForm( const AForm& other ) :
_name(other._name),
_isSigned(other._isSigned),
_gradeNeededToSign(other._gradeNeededToSign),
_gradeNeededToExecute(other._gradeNeededToExecute)
{

}

AForm& AForm::operator=( const AForm& rhs ){
    if (this == &rhs){
        return (*this);
    }
    this->_isSigned = rhs._isSigned;
    return (*this);
}

const std::string AForm::getName( void ) const{
    return this->_name;
}

bool AForm::getIsSigned( void ) const{
    return this->_isSigned;
}

const int AForm::getGradeNeededToSign( void ) const{
    return this->_gradeNeededToSign;
}

const int AForm::getGradeNeededToExecute( void ) const{
    return this->_gradeNeededToExecute;
}

void AForm::beSigned( Bureaucrat& bureaucrat ){
    int grade = bureaucrat.getGrade();
    if (grade > this->_gradeNeededToSign)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

const char * AForm::GradeTooHighException::what() const throw(){
    return "Grade Too High";
}

const char * AForm::GradeTooLowException::what() const throw(){
    return "Grade Too Low";
}

std::ostream	&operator<<(std::ostream &ost, const AForm& form){
    ost << "name: " << form.getName() << ", isSigned: " << form.getIsSigned() << ", gradeNeededToSign: " << form.getGradeNeededToSign() << ", gradeNeededToExecute: " << form.getGradeNeededToExecute();
    return ost;
}