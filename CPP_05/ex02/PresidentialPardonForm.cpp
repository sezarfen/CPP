#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
: AForm() // calling default constructor for AForm also
{
	// nothing to do I think
}

PresidentialPardonForm::~PresidentialPardonForm( void ){
	// nothing to do I think
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
: AForm(other)
{
	int executeGrade = other.getGradeNeededToExecute();
	int signGrade = other.getGradeNeededToSign();

	// AForm already checks 1 right?
	if (executeGrade > 5)
		throw AForm::GradeTooLowException();
	else if (signGrade > 25)
		throw AForm::GradeTooHighException();
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& rhs ){
	if (this == &rhs){
		return (*this);
	}
	// what can be done here?
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ){
	this->_target = target;
}
