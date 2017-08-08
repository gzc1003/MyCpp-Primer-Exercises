#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    vector<int> scores(11, 0);
    auto it = scores.begin();
    unsigned grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++(*(it + grade / 10));
    }
    for (auto n : scores)
        cout << n << " ";
    cout << endl;
    return 0;
}