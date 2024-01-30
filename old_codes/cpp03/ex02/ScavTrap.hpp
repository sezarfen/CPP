#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:

	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		~ScavTrap( void );

		void attack(const std::string & name);
		
		void guardGate( void );
};

#endif /* end of CLAPTRAP_HPP */