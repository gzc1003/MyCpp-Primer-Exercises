#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
    unsigned a = 10, b = 42;
    int c = 10, d = 42;
    cout << c - d << endl;
    cout << a - b << endl;
    printf("c-d= %.2x\n", c - d);
    printf("a-b= %.2x\n", a - b);
    return 0;
}