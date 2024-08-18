#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm& other );
	public:
		~ShrubberyCreationForm( void );

		ShrubberyCreationForm( std::string target );

		ShrubberyCreationForm& operator=( const ShrubberyCreationForm& rhs );

		void execute(Bureaucrat const & executor) const;
};

# endif /* end of SHRUBBERYCREATIONFORM_HPP */