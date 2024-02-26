NAME=ex02
SRCS=Animal.cpp Dog.cpp Cat.cpp main.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
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
