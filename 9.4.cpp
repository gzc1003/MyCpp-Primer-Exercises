#include <vector>
using std::vector;
#include <iostream>


bool find_value(vector<int>::const_iterator beg,
    vector<int>::const_iterator end,
    int i)
{
    while (beg != end) {
        if (*beg++ == i)
            return true;
    }
    return false;
}

int main()
{
    vector<int> vec{ 1,2,3,4,5,6 };
    std::cout << find_value(vec.begin(), vec.end(), 4) << std::endl;
    return 0;
}
