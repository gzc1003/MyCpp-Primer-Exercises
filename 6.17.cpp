#include <string>
using std::string;
#include <cctype>
#include <iostream>
using std::cout; using std::endl; using std::cin;

bool have_uppercase(const string &s)
{
    for (auto c : s) {
        if (isupper(c))
            return true;
    }
    return false;
}

void to_lowercase(string &s)
{
    for (auto &c : s) {
        c = tolower(c);
    }
}

int main()
{
    cout << have_uppercase("helloWorld") << endl;
    string s = "HELLO";
    to_lowercase(s);
    cout << s << endl;
}