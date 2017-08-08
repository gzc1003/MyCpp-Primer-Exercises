#include <iostream>
using std::istream;
#include <sstream>
using std::istringstream;
#include <string>
using std::string;



istream &read_print(istream &strm)
{
    string s;
    while (strm >> s)
        std::cout << s << std::endl;
    strm.clear();
    return strm;
}

int main()
{
    istream &res = read_print(std::cin);
    std::cout << res.rdstate() << std::endl;

    istringstream is("hello world!");
    read_print(is);
    return 0;
}

