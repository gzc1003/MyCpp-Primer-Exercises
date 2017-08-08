#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string; 

void fnd(const string &s) 
{
    string number("0123456789"), 
        alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    for (string::size_type pos = 0;; (pos = s.find_first_of(number, pos)) != s.npos;) {
        cout << "found number at index: " << pos
            << " number is " << s[pos] << endl;
        ++pos;
    }

    for (string::size_type pos = 0;; (pos = s.find_first_of(alphabet, pos)) != s.npos;) {
        cout << "found letter at index: " << pos
            << " letter is " << s[pos] << endl;
        ++pos;
    }
}


int main()
{
    string s("ab2c3d7R4E6");
    fnd(s);
    return 0;
}