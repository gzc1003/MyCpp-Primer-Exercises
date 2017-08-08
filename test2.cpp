#include <iostream>
using namespace std;

class foo {
public:
    explicit foo(int i) : a(i) { }
    int a = 1, b = 2;
};


int main()
{
    foo bar = static_cast<foo>(4);
    cout << bar.a << " " << bar.b << endl;
}