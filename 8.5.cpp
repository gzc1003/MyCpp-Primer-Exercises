#include <fstream>
#include <iostream>
#include <vector>
#include <string>


int main(int argc, char *argv[])
{
    std::vector<std::string> v;
    std::ifstream input(argv[1]);
    if (input) {
        std::string word;
        while (input >> word)
            v.push_back(word);
    } else {
        std::cerr << "couldn't open:" + std::string(argv[1]);
    }
    for (auto &word : v)
        std::cout << word << std::endl;
    return 0;
}