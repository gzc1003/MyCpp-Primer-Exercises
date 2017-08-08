#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> integers;
    int tmp;
    decltype(integers.size()) i;
    while (cin >> tmp)
        integers.push_back(tmp);
    for (i = 0; i + 1 < integers.size(); i = i + 2) {
        cout << integers[i] + integers[i + 1] << " ";
    }
    if (i < integers.size())
        cout << integers[i];
    cout << endl;
    return 0;
}