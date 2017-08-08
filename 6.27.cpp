#include <initializer_list>
#include <iostream>

int sum(std::initializer_list<int> lst)
{
    int ret = 0;
    for (auto i : lst)
        ret += i;
    return ret;
}

int main()
{
    std::cout << sum({ 1,2,3,4 });
    return 0;
}