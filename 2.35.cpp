#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    const int i = 42;
    auto j = i;
    auto &k = i;
    auto *p = &i;
    const auto j2 = i, &k2 = i;
    
    cout << typeid(j).name() << '\n'
        << typeid(k).name() << '\n'
        << typeid(p).name() << '\n'
        << typeid(j2).name() << '\n'
        << typeid(k).name() << '\n';

    return 0;
}
