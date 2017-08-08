#include <string>
using std::string;

#include <iostream>
using std::cin; using std::cout; using std::endl;

int main()
{
    double grade=0;
    while (cin >> grade) {
        string finalgrade = (grade > 90) ? "high pass"
            : (grade > 75) ? "pass"
            : (grade < 60) ? "fail" : "low pass";
        cout << finalgrade << endl;
    }
    return 0;
}