#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat( void );
        ~Bureaucrat( void );
        Bureaucrat( const Bureaucrat& other );
        Bureaucrat( int grade );
        Bureaucrat( std::string name);
        Bureaucrat( std::string name , int grade );

        Bureaucrat& operator=( const Bureaucrat& rhs );

        std::string getName( void ) const;
        int getGrade( void ) const;

        void incrementGrade( int amount );
        void decrementGrade( int amount );

        /*
            void func() throw(int, double);  // func can only throw int or double
            void func() throw();             // func cannot throw any exceptions

            throw() with an empty list specifically means that
            the function is not supposed to throw any exceptions.
            If it does, std::unexpected() is invoked, which typically
            leads to std::terminate() being called, ending the program.

            with throw(), that function promises not to throw something
        */

        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw(); // newer versions uses noexcept except for throw()
        };

        class GradeTooLowException : public std::exception{
            virtual const char* what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &ost, const Bureaucrat& bur);

#endif /* end of BUREAUCRAT_HPP */