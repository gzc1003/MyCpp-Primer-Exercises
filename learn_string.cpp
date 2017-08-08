#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

int main()
{
    string s;
    string &rs = s.insert(0, "hello");
    rs[0] = 'H';
    cout << -1 % 256 << endl;

    unsigned i = -1;
    int j = i;
    cout << "i= " << i << endl;
    cout << "j= " << j << endl;

    return 0;
}