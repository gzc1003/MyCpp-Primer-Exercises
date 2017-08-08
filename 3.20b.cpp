#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> integers;
    for (int n = 0; cin >> n; integers.push_back(n));
    string::size_type start = 0, end = integers.size() - 1;
    for (; start < end; ++start, --end) {
        cout << integers[start] + integers[end] << " ";
    }
    if (start == end)
        cout << integers[start] + integers[end];
    cout << endl;
    return 0;
}