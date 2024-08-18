#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
: AForm() // calling default constructor for AForm also
{
	// nothing to do I think
}

RobotomyRequestForm::~RobotomyRequestForm( void ){
	// nothing to do I think
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )
: AForm(other)
{
	int executeGrade = other.getGradeNeededToExecute();
	int signGrade = other.getGradeNeededToSign();

	// AForm already checks 1 right?
	if (executeGrade > 45)
		throw AForm::GradeTooLowException();
	else if (signGrade > 72)
		throw AForm::GradeTooHighException();
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs ){
	if (this == &rhs){
		return (*this);
	}
	// what can be done here?
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ){
	this->_target = target;
}
