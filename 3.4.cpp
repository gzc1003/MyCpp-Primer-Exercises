#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1, str2, output;
    cin >> str1 >> str2;

    if (str1 > str2)
        output = str1;
    else
        output = str2;
    cout << output << endl;
    return 0;
}