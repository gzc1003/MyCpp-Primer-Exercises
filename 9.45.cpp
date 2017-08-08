#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

string add_prefix_postfix(string s, const string prefix, const string postfix)
{
    s.insert(s.begin(), prefix.begin(), prefix.end());
    s.append(postfix);
    return s;
}

int main()
{
    string s("Guo");
    cout << add_prefix_postfix(s, "Mr.", "II") << endl;
    return 0;
}