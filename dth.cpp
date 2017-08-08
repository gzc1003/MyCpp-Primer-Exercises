#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout; using std::endl;

int main()
{
    const string hex = "0123456789ABCDEF";
    string::size_type n;
    string output;
    while (cin >> n) {
        if (n < hex.size())
            output += hex[n];
    }
    cout << output << endl;
}