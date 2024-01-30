#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie( std::string name );
		Zombie(void);
		~Zombie(void);
		void announce( void );

		std::string getName(void);
		void setName(std::string name);
};

#endif /*end of ZOMBIE_H*/