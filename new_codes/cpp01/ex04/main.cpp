#include <iostream>
#include <fstream>


int main(int argc, char *argv[])
{
    /*
    if (argc != 4)
    {
        std::cout << "Please use this format : " << " ./program [file_name] [string 1] [string 2]" << std::endl;
    }
    */
    // TODO: Error handling to check arguments giving correctly or not

    // File progress
    std::ofstream file;

    file.open(argv[1]);
    file << "Something written on this file" << std::endl;
    file.close();

    return (0);
}