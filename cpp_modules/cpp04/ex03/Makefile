NAME=ex03
SRCS=AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
CFLAGS=-Werror -Wall -Wextra -std=c++98
CC=c++

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
