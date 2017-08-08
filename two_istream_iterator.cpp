#include <vector>
#include <string>
#include <iostream>
#include <iterator>

using std::vector;
using std::string;

int main()
{
    std::istream_iterator<string> in_iter(std::cin), in_iter2(std::cin);
    ++in_iter;
    std::cout << *in_iter;
    std::cout << *in_iter2;
    return 0;
}
