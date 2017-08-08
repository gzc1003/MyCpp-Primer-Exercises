#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

typedef int F(int, int);
using FP = F*;

int add(int a, int b)
{
    return a + b;
}


int sub(int a, int b)
{
    return a - b;
}



int mul(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}



int main()
{
    vector<FP> v{add, sub, mul, divide};

    for (auto p : v)
        cout << p(6, 3) << endl;

    return 0;
}
