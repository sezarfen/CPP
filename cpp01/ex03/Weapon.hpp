#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(std::string);
		Weapon(void);
		const std::string	&getType(void);
		void				setType(std::string newType);
};

#endif /* end of WEAPON_H */