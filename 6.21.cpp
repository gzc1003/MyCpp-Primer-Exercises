#include <iostream>
using std::cout; using std::endl;

int larger(const int a, const int *b)
{
    return a < *b ? *b : a;
}

int main()
{
    int a = 1, b = 2;       
    cout << larger(a, &b) << endl;
    return 0;
}