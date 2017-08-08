#include <string>
using std::string;
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    string pre_str, max_str;
    unsigned cnt = 1, max_rpt=1;
    if (cin >> pre_str) {
        string str;
        while (cin >> str) {
            if (str == pre_str)
                ++cnt;
            else {
                pre_str = str;
                cnt = 1;
            }
            if (cnt > max_rpt) {
                max_rpt = cnt;
                max_str = str;
            }
        }
        if (max_rpt != 1)
            cout << "maximum repeated word is \"" << max_str << "\", times: " << max_rpt << endl;
        else
            cout << "No repeat" << endl;
    } else
        cout << "No input words" << endl;

    return 0;
}