#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v5{ 10,42 };
    std::cout << "The size of v5 is " << v5.size() << std::endl;
    for (auto n : v5)
        std::cout << n << " ";
    std::cout << std::endl;
    return 0;
}


