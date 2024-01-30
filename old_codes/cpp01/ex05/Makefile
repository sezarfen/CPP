NAME = Harl

SRCS = Harl.hpp Harl.cpp main.cpp
CC = g++
CFLAGS = -Werror -Wall -Wextra -std=c++98

all: $(NAME)

$(NAME):
	g++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.gch

fclean: clean
	rm -rf a.out
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re