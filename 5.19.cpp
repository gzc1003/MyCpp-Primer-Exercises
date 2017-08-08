#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
    do {
        cout << "Please input two strings" << endl;
        string str1, str2;
        cin >> str1 >> str2;
        cout << (str1.size() < str2.size() ? str1 : str2) << endl;
    } while (cin);
    return 0;
}