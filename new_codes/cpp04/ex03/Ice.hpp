#ifndef ICE_HPP
# define ICE_HPP

class Ice : public AMateria
{
    public:
        Ice( void );
        Ice( const Ice& other );
        Ice( const std::string rightOne );

        ~Ice( void );
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif /* end of ICE_HPP */