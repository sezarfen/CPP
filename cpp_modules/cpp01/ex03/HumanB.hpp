#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
private:
	Weapon *weapon;
	std::string name;
public:
	HumanB( std::string name );
	
	void 	attack( void );
	void	setWeapon( Weapon &weapon );
};

#endif /* end of HUMANB_HPP */