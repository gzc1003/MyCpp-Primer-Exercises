#include <iostream>
#include <string>

using namespace std;

int main()
{
    string output, tmp;
    if (cin >> output) {
        while (cin >> tmp)
            output += ' ' + tmp;
        cout << output << endl;
    } else {
        cerr << "No input" << endl;
    }
}