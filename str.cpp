#include <iostream>
#include <string>


int i(1);
int j{ 2 };

using std::cin;
using std::cout; 
using std::endl;
using std::string;
using std::getline;


int main()
{   
    int k;
    if (cin >> k)
        cout << "k: " << k << endl;

    string str;
    cin >> str;
    cout << str << endl;
    getline(cin, str);
    cout << str << endl;
    cout << "str size:" << str.size() << endl;

    cout << true << endl;
    cout << i << endl;
    cout << j << endl;
    return 0;
}