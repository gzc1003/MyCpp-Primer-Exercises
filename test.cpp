#include <vector>
using std::vector;
#include <iostream>

int sum(vector<int>::iterator beg, vector<int>::iterator end)
{
    int ret=0;
    for (vector<int>::iterator iter = beg; iter != end; ++iter)
        ret += *iter;
    return ret;
}

int main()
{
    vector<int> v = { 1,2,3,4 };
    std::cout << sum(v.begin(), v.end());

    for (auto i : { 1,2,3 })
        std::cout << i;
    return 0;
} 