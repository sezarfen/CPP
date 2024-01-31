#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (EXIT_SUCCESS);
	}
	for (size_t i = 1; i < argc; i++) {
		int len = strlen(argv[i]);
		for (size_t j = 0; j < len; j++) {
			std::cout << (char)toupper(argv[i][j]);
		}
	}
	return 0;
}
