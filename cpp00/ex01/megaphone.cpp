#include <iostream>

void	print_words(char *av_i)
{
	int	i;
	
	i = 0;
	while (av_i[i])
	{
		std::cout << (char) std::toupper(av_i[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
		{
			print_words(av[i]);
			if (i + 1 != ac)
				std::cout << " ";
		}
		std::cout << std::endl;
	}	
	return (0);
}
