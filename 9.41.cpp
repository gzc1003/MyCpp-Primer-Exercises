#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

int main()
{
    vector<char> v1{ 'h', 'e', 'l','l','o' };
    string s(v1.begin(), v1.end());
    cout << s << endl;
    return 0;
}