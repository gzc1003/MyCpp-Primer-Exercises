#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

int main(int argc, char *argv[])
{
    string res;
    for (int i = 1; i != argc; ++i) {
        res += string(argv[i]) + " ";
    }
    cout << res<< endl;
    return 0;
}