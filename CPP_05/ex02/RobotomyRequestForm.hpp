#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

		RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm& other );
	public:
		~RobotomyRequestForm( void );

		RobotomyRequestForm( std::string target );

		RobotomyRequestForm& operator=( const RobotomyRequestForm& rhs );

		void execute(Bureaucrat const & executor) const;
};

# endif /* end of ROBOTOMYREQUESTFORM_HPP */