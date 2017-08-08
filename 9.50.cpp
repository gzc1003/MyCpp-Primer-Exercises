#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;

int main()
{
    vector<string> vec{ "12", "34", "42" };
    int sum = 0;
    for (auto &s : vec) {
        sum += std::stoi(s);
    }
    cout << sum << endl;
    return 0;
}