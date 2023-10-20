NAME = inheritance
SRCS = ClapTrap.hpp ScavTrap.hpp ClapTrap.cpp ScavTrap.cpp main.cpp
CC = g++
CFLAGS = -Werror -Wall -Wextra -std=c++98 

all: $(NAME)

$(NAME):
	g++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.gch

fclean: clean
	rm -rf inheritance

re: fclean all

.PHONY = all clean fclean re