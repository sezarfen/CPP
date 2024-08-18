#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeNeededToSign;
        const int _gradeNeededToExecute;
    public:
        Form( void );
        Form( std::string name, int gradeNeededToSign, int gradeNeededToExecute );
        ~Form( void );
        Form( const Form& other );

        Form& operator=( const Form& rhs );

        const std::string getName( void ) const;
        bool getIsSigned( void ) const;
        const int getGradeNeededToSign( void ) const;
        const int getGradeNeededToExecute( void ) const;

        void beSigned( Bureaucrat& bur );

        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw(); // newer versions uses noexcept except for throw()
        };

        class GradeTooLowException : public std::exception {
            const virtual char* what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &ost, const Form& form);

#endif /* end of FORM_HPP */