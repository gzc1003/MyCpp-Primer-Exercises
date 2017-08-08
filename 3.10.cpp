#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    cout << str << endl;
    for (auto c : str) 
        if (!ispunct(c))
            cout << c;
    cout << endl;
    return 0;
}