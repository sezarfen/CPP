#include <iostream>

std::string replace_all(
    const std::string & str ,   // where to work
    const std::string & find ,  // substitute 'find'
    const std::string & replace //      by 'replace'
) {
    using namespace std;
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
/*
    This code might be an improvement to James Kanze's
    because it uses std::string methods instead of
    general algorithms [as 'std::search()'].
*/
}

int main(int argc, char *argv[])
{
    std::string test = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    std::cout << replace_all(test, "e", "x") << std::endl;
    return (0);
}