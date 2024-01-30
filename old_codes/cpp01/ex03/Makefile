NAME= BraiiiiiiinnnzzzZ

SRCS= HumanA.cpp HumanA.hpp HumanB.cpp HumanB.hpp main.cpp Weapon.cpp Weapon.hpp
GCC = g++
CFLAGS = -Werror -Wall -Wextra -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	g++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.gch

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re