#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

int main()
{
    int grade;
    string lettergrade;
    vector<string> letters{ "F", "D", "C", "B", "A", "A++" };
    while (cin >> grade) {
        if (grade < 60)
            lettergrade = letters[0];
        else {
            lettergrade = letters[(grade - 50) / 10];
            if (grade != 100) {
                if (grade % 10 < 3)
                    lettergrade += '-';
                else if (grade % 10 > 7)
                    lettergrade += '+';
            }
        }
        cout << lettergrade << endl;
    }

    return 0;
}