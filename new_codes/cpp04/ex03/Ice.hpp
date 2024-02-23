#ifndef ICE_HPP
# define ICE_HPP

class Ice
{
    private:
        // there might be some attributes

    public:
        Ice( void );
        Ice( const Ice& other );
        ~Ice( void );

        Ice& operator=( const Ice& rightOne );

        // override
        virtual AMateria* clone() const;
};

#endif /* end of ICE_HPP */