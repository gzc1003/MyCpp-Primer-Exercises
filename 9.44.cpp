#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

void old_to_new(string &s, const string &oldVal, const string &newVal)
{
    for (string::size_type i = 0; i != s.size();) {
        if (oldVal == s.substr(i, oldVal.size())) {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size();
        } else
            ++i;
    }
}

int main()
{
    string s("thothru");

    old_to_new(s, "tho", "though");
    cout << s << endl;
    old_to_new(s, "thru", "through");
    cout << s << endl;

    return 0;
}