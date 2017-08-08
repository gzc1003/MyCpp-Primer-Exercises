#include <numeric>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;


int main()
{
    string s;
    string s1("");

    vector<int> vec{ 0,1,2,3,4 };
    auto sum = std::accumulate(vec.cbegin(), vec.cend(), 0.0);
    cout << sum << endl;   // sum type is double
    double d = 11.0;
    cout << d << endl;
    return 0;
}
