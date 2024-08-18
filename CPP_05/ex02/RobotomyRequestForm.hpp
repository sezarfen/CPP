#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( void );
		~RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm& other );

		RobotomyRequestForm( const AForm& target );

		RobotomyRequestForm& operator=( const RobotomyRequestForm& rhs );
};

# endif /* end of ROBOTOMYREQUESTFORM_HPP */