#include <iostream>
#include <fstream>


// This link might be useful for replacing occurence in the string
// https://stackoverflow.com/questions/20406744/how-to-find-and-replace-all-occurrences-of-a-substring-in-a-string

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Wrong format of using program, Please use this format:" << std::endl;
        std::cout << "./[program_name] [file_to_read] [string to change] [new string]" << std::endl;
        return (1);
    }

    std::ifstream fileToRead(argv[1], std::ios::binary);
    if (!fileToRead.is_open())
    {
        std::cout << "Failed to open file to read." << std::endl;
        return (1);
    }

    // generating <file_name>.replace
    std::string replace(argv[1]);
    replace = replace + ".replace";

    std::ofstream fileToWrite(replace, std::ios::binary);
    if (!fileToWrite.is_open())
    {
        std::cout << "Failed to open file to write" << std::endl;
        return (1);
    }
    
    // writing from input to output file
    fileToWrite << fileToRead.rdbuf();

    // closing files
    fileToRead.close();
    fileToWrite.close();
    return (0);
}