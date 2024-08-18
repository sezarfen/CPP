#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeNeededToSign;
        const int _gradeNeededToExecute;
    public:
        AForm( void );
        AForm( std::string name, int gradeNeededToSign, int gradeNeededToExecute );
        ~AForm( void );
        AForm( const AForm& other );

        AForm& operator=( const AForm& rhs );

        const std::string getName( void ) const;
        bool getIsSigned( void ) const;
        virtual const int getGradeNeededToSign( void ) const;
        virtual const int getGradeNeededToExecute( void ) const;

        virtual void beSigned( Bureaucrat& bur );

        virtual void execute(Bureaucrat const & executor) const;

        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw(); // newer versions uses noexcept except for throw()
        };

        class GradeTooLowException : public std::exception {
            const virtual char* what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &ost, const AForm& form);


#endif /* end of AFORM_HPP */