#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    int tmp;
    vector<int> integers;
    while (cin >> tmp)
        integers.push_back(tmp);
    for (auto num : integers)
        cout << num << endl;
    return 0;
}