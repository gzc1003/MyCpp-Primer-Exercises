#include <iostream>
using std::cout; using std::endl;
#include <iterator>
using std::begin; using std::end;
#include <cstddef>
using std::size_t;


void print(const int (&arr)[2])
{
    for (auto i : arr)
        cout << i << endl;
}

void print(const int *beg, const int *end)
{
    for (auto p = beg; p != end; ++p)
        cout << *p << endl;
}

void print(const int *p, size_t size)
{
    for (size_t i = 0; i != size; ++i)
        cout << p[i] << endl;
}


int main()
{
    int i = 0, j[2] = { 0,1 };
    print(j);
    print(begin(j), end(j));
    print(j, 2);
    return 0;
}