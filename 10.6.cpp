#include <algorithm>
#include <vector>
using std::vector;
#include <iostream>
using std::cout;

int main()
{
    vector<int> vec{ 0,1,2,3 };
    for (auto i : vec) cout << i << " ";
    cout << std::endl;
    std::fill_n(vec.begin(), vec.size(), 0);
    for (auto i : vec) cout << i << " ";


    vector<int> vec2;
    vec.reserve(10);
    std::fill_n(vec2.begin(), 10, 0);  //no compile error, is runtime error
    return 0;
}