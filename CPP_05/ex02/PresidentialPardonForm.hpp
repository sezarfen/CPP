#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

		PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm& other );
	public:
		~PresidentialPardonForm( void );

		PresidentialPardonForm( std::string target );

		PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );

		void execute(Bureaucrat const & executor) const;
};

# endif /* end of PRESIDENTIALPARDONFORM_HPP */