#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <string>
using std::string;

int main()
{
    string pre_str;
    if (cin >> pre_str) {
        string str;
        while (cin >> str) {
            if (str == pre_str) {
                cout << "repeated word is " << str << endl;
                break;
            } else
                pre_str = str;
        }
        if (!cin)
            cout << "no repeat" << endl;
    } else
        cout << "no input" << endl;
    return 0;
}