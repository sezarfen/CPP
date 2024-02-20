#ifndef AMATERIA_HPP
# define AMATERIA_HPP

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria( void );
        AMateria( std::string const& type);
        ~AMateria( void );

        AMateria& operator=( const AMateria& rightOne );

        std::string const& getType( void ) const; //Returns the materia type

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
}

#endif /* end of AMATERIA_HPP */