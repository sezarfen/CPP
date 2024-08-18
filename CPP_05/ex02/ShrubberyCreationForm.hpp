#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm( void );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );

		ShrubberyCreationForm( const AForm& target );

		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& rhs );
};

# endif /* end of SHRUBBERYCREATIONFORM_HPP */