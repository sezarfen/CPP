NAME=harl
SRCS=main.cpp Harl.cpp
CFLAGS=-Werror -Wall -Wextra -std=c++98
CC=g++

all: $(NAME)

# Order is important for $(SRCS) -o $(NAME)
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re