#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm( void );
		~PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm& other );
		
		PresidentialPardonForm( const AForm& target );

		PresidentialPardonForm& operator=( const PresidentialPardonForm& rhs );
};

# endif /* end of PRESIDENTIALPARDONFORM_HPP */