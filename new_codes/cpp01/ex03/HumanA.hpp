#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
private:
	Weapon &weapon;
	std::string name;
public:
	HumanA( std::string name, Weapon weapon );

	void	attack( void );
};

#endif /* end of HUMANA_HPP */