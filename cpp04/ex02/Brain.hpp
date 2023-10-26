#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	
	public:
		Brain( void );
		~Brain( void );
		Brain(const Brain & other);

		Brain & operator = (const Brain & other);
};

#endif /* end of BRAIN_HPP */