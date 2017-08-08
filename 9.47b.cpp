#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

void fnd(const string &s)
{
    string number("0123456789"),
        alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");

    string::size_type pos = 0;
    while ((pos = s.find_first_not_of(alphabet, pos)) != string::npos) {
        cout << "found number at index: " << pos
            << " number is " << s[pos] << endl;
        ++pos;
    }

    pos = 0;
    while ((pos = s.find_first_not_of(number, pos)) != string::npos) {
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