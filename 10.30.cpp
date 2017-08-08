#include <iterator>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::vector;

int main()
{
    std::istream_iterator<int> in_iter(std::cin), eof;
    vector<int> vec;
    std::copy(in_iter, eof, std::back_inserter(vec));
    sort(vec.begin(), vec.end());
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::copy(vec.cbegin(), vec.cend(), out_iter);
    std::cout << std::endl;
    return 0;
}