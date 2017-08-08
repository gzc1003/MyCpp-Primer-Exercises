#include <fstream>
#include <iostream>
#include <vector>
#include <string>


int main(int argc, char *argv[])
{
    std::vector<std::string> v;
    std::ifstream input(argv[1]);
    if (input) {
        std::string line;
        while (std::getline(input, line))
            v.push_back(line);
    } else {
        std::cerr << "couldn't open:" + std::string(argv[1]);
    }
    for (auto &line : v)
        std::cout << line << std::endl;
    return 0;
}