#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( std::string name );
		~FragTrap( void );

		void attack(const std::string & name);
		void highFivesGuys(void);
};

# endif /* end of FRAGTRAP_HPP */