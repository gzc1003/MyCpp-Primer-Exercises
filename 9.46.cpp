#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

string add_prefix_postfix(string s, const string prefix, const string postfix)
{
    s.insert(0, prefix);
    s.insert(s.size(), postfix);
    return s;
}

int main()
{
    string s("Guo");
    cout << add_prefix_postfix(s, "Mr.", "II") << endl;
    return 0;
}