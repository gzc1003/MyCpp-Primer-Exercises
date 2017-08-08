#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;
#include <cctype>
using std::isupper;

int main()
{
    string pre_str;
    if (cin >> pre_str) {
        string str;
        while (cin >> str) {
            if (str == pre_str) {
                if (isupper(str[0])) {
                    cout << "repeated word is " << str << endl;
                    break;
                } else
                    continue;
            }
            pre_str = str;
        }
        if (!cin)
            cout << "no repeat" << endl;
    } else
        cout << "no input" << endl;
    return 0;
}