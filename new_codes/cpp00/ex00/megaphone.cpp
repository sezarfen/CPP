#include <iostream>
#include <string>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int main (int argc, char *argv[]) {
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}
	for (size_t i = 1; i < argc; i++) {
		int len = ft_strlen(argv[i]);
		for (size_t j = 0; j < len; j++) {
			std::cout << (char)toupper(argv[i][j]);
		}
		std::cout << " ";
	}
	return 0;
}
