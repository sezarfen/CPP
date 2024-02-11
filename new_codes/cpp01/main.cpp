#include <iostream>
#include <string>
#include <iomanip>

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

int main()
{
    std::string s1 = "Herkese selam arkadaşlar, selam ornek bir kod bloğu ile beraberiz";
    std::string find = "selam";
    std::string to_replace = "selamlar";
    std::string newString;
    size_t pos, from = 0;

    while (std::string::npos != (pos = s1.find(find, from)))
    {
        newString.append(s1, from, pos-from); // fromdan pos-from kadar ileri gideceğiz
        newString.append(to_replace);
        from = pos + find.size();
    }
    newString.append(s1, from, std::string::npos);
    std::cout << newString << std::endl;
    return (0);
}