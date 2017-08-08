#include <iostream>
using std::cout; using std::endl; using std::cin;

int fact(int);

int interactive_fact();


int main()
{
    cout << interactive_fact() << endl;
    return 0;
}

int fact(int n)
{
    int ret = 1;
    while (n > 1)
        ret *= n--;
    return ret;
}

int interactive_fact()
{
    int n, ret;
    cout << "input an integer: ";
    cin >> n;
    ret = fact(n);
    return ret;
}