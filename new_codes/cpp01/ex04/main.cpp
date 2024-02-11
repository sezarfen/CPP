#include <fstream>
#include <iostream>
#include <sstream> // for std::stringstream


std::string replace_all(const std::string & str, const std::string & find, const std::string & replace)
{
    std::string result;
    size_t find_len = find.size();
    size_t pos,from=0;
    while ( std::string::npos != ( pos=str.find(find,from) ) ) {
        result.append( str, from, pos-from );
        result.append( replace );
        from = pos + find_len;
    }
    result.append( str, from , std::string::npos );
    return result;
}


int main(int argc, char *argv[])
{

    // check if the number of arguments giving correctly
    if (argc != 4)
    {
        std::cout << "Wrong format of using program, Please use this format:" << std::endl;
        std::cout << "./[program_name] [file_to_read] [string to change] [new string]" << std::endl;
        return (1);
    }

    // opening file we want to read from
    std::ifstream fileToRead(argv[1], std::ios::binary);
    if (!fileToRead.is_open())
    {
        std::cout << "Failed to open file to read." << std::endl;
        return (1);
    }

    // reading the file into temporary stringstream // with the help of the stringstream we can use <<
    std::stringstream temp;
    temp << fileToRead.rdbuf();

    // generating <file_name>.replace
    std::string changedName = argv[1];
    changedName.append(".replace");

    // opening file we want to write inside of it
    std::ofstream fileToWrite(changedName.c_str());
    if (!fileToWrite.is_open())
    {
        std::cout << "Failed to open file to write" << std::endl;
        return (1);
    }

    // turning (char *) to (std::string) by using std::string constructors
    std::string toSearch(argv[2]);
    std::string toReplace(argv[3]);
    
    // replaced string to write inside of the <name>.replace file
    std::string newText = replace_all(temp.str(), toSearch, toReplace);

    // writing from input to output file
    fileToWrite << newText;

    // closing files
    fileToRead.close();
    fileToWrite.close();
    return (0);
}