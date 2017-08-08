#include <vector>
using std::vector;
#include <iostream>


auto find_value(vector<int>::const_iterator beg,
    vector<int>::const_iterator end,
    int i) -> vector<int>::const_iterator
{
    while (beg != end) {
        if (*beg == i)
            break;
        ++beg;
    }
    return beg;
}

int main()
{
    vector<int> vec{ 1,2,3,4,5,6 };
    auto iter = find_value(vec.begin(), vec.end(), 4);
    if (iter != vec.end())
        std::cout << *iter << std::endl;
    else 
        std::cout << "not find" << std::endl;
    return 0;
}
