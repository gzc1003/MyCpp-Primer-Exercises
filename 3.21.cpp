#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

int main()
{
    std::vector<int> v5 = { 10,42 };
    cout << "The size of vector is: " << v5.size() << endl;
    for (auto it = v5.cbegin(); it != v5.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}