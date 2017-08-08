#include <iostream>
using namespace std;

int main()
{
    int value, sum=0;
    while (cin >> value)
        sum += value;
    cout << sum;
    return 0;
}