#include <fstream>
#include <iostream>
#include <sstream> // in order to use std::stringstream

std::string replace_all(const std::string & str, const std::string & find, const std::string & replace)
{
    std::string result;
    size_t find_len = find.size();
    size_t pos,from=0;
    while ( std::string::npos != ( pos=str.find(find,from) ) ) {
        result.append( str, from, pos-from ); // aradığımız kelimeden öncesini ekleme yapıyoruz
        result.append( replace ); // aradığımız kelimeyi ekliyoruz
        from = pos + find_len; // başlama pozisyonunu kelimeden sonrasına atama yapıyoruz
    }
    result.append( str, from , std::string::npos );
    return result;
}

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

    std::stringstream temp;
    temp << fileToRead.rdbuf();

    std::string changedName = argv[1];
    changedName.append(".replace");

    std::ofstream fileToWrite(changedName.c_str());
    if (!fileToWrite.is_open())
    {
        std::cout << "Failed to open file to write" << std::endl;
        return (1);
    }

    std::string toSearch(argv[2]);
    std::string toReplace(argv[3]);
    
    std::string newText = replace_all(temp.str(), toSearch, toReplace);

    fileToWrite << newText;

    fileToRead.close();
    fileToWrite.close();
    return (0);
}