#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <deque>

using std::vector;
using std::deque;
using std::cout; using std::endl;


int main()
{
    vector<int> vec{ 1,2,3,4,5,6,7,8,9 };
    deque<int> vec1, vec2, vec3;
    std::copy(vec.cbegin(), vec.cend(), 
        std::inserter(vec1, vec1.begin()));
    std::copy(vec.cbegin(), vec.cend(),
        std::front_inserter(vec2));
    std::copy(vec.cbegin(), vec.cend(),
        std::back_inserter(vec3));
    cout << "inserter: ";
    for (auto i : vec1) cout << i << " ";
    cout << endl;
    cout << "front_inserter: ";
    for (auto i : vec2) cout << i << " ";
    cout << endl;
    cout << "back_inserter: ";
    for (auto i : vec3) cout << i << " ";
    cout << endl;
    return 0;
}