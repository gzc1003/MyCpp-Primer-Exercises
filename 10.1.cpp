#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <string>

int main()
{
    std::vector<int> vec{ 1,2,3,4,5,1,3,1 };
    std::cout << std::count(vec.cbegin(), vec.cend(), 1) 
        << std::endl;

    std::list < std::string > lst{ "aa", "bb", "cc", "aa"};
    std::cout << std::count(lst.cbegin(), lst.cend(), "aa")
        << std::endl;
    return 0;
}