#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;


bool more_than_5(const string &s)
{
    return s.size() >= 5;
}

int main()
{
    vector<string> vec{ "hello", "world", "guo", "zi", "chun", "exercise" };
    auto it = std::partition(vec.begin(), vec.end(), more_than_5);
    for (auto start = vec.begin(); start != it; ++start)
        std::cout << *start << std::endl;
    return 0;
}