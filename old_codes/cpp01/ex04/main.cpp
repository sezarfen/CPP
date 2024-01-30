#include <iostream>
#include <fstream>

/* args -> filename, s1, s2 */
int main(int ac, char **av)
{
	std::ifstream file_to_read;
	std::ofstream file_to_write;
	std::string buffer;

	/*		 	 ERROR CHECK			*/

	if (ac != 4)
	{
		std::cerr << "Wrong number of argumants given!" << std::endl;
		return (1);
	}

	/* 			OPEN FILES AND CHECK IF ERROR OCCURED  			*/

	// OPEN FILE TO READ

	file_to_read.open(av[1], std::ios::in | std::ios::out);
	if (!file_to_read.is_open())
	{
		std::cerr << "Problem occur while try to open the file or the file does not exists." << std::endl;
		return (1);
	}

	// OPEN FILE TO WRITE AND SET FILENAME
	
	std::string file_name(av[1]);
	file_name.append(".replace");
	file_to_write.open(file_name.c_str()); // because it wants char *
	if (!file_to_write.is_open())
	{
		std::cerr << "Problem occur while try to open the file." << std::endl;
		return (1);
	}

	// change double char pointers to strings

	int index = 0;
	std::string s1(av[2]);
	std::string s2(av[3]);

	// READ INTO BUFFER // THEN READ INTO FILE

	while ((getline(file_to_read, buffer)))
	{
		index = 0;
		while (buffer.find(s1, index) != std::string::npos)
		{
			index = buffer.find(s1, index);
			buffer.erase(index, s1.length());
			buffer.insert(index, s2);
		}
		buffer.append("\n");
		file_to_write << buffer;
	}

	return (0);
}