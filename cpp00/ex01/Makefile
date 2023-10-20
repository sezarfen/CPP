NAME = megaphone
SRCS = megaphone.cpp
CC = g++
CFLAGS = -Werror -Wall -Wextra -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	g++ $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re