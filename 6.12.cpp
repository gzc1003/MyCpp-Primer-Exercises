#include <iostream>
using std::cout; using std::endl; using std::cin;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 1, b = 2;
    cout << "a = " << a << " b = " << b << endl;
    swap(a, b);
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}