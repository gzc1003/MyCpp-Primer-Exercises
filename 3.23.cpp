#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> integers{ 0,1,2,3,4,5,6,7,8,9 };
    for (auto it = integers.begin(); it != integers.end(); ++it) {
        *it = *it * 2;
    }
    for (auto n : integers)
        cout << n << " ";
    cout << endl;
    return 0;
}