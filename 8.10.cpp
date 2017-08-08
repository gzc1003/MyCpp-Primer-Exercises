#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;
#include <fstream>
using std::ifstream;
#include <iostream>

int main(int argc, char *argv[])
{
    vector<string> vec;
    ifstream input_file(argv[1]);
    string buf;
    while (std::getline(input_file, buf))
        vec.push_back(buf);
    for (auto &s : vec) {
        istringstream is(s);
        string tmp;
        while (is >> tmp)
            std::cout << tmp << std::endl;
    }

    return 0;
}