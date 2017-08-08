#include <iterator>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;

int main()
{
    std::ifstream input_file("poem.txt");
    if (!input_file) {
        std::cerr << "fail to open" << std::endl;
        return -1;
    }
    std::istream_iterator<string> in_iter(input_file), eof;
    vector<string> words(in_iter, eof);

    for (auto s : words) std::cout << s << " ";
    std::cout << std::endl;
    return 0;
}