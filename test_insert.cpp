#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    vector<int> v1{ 0,1,2,3 };
    cout << *(v1.insert(v1.end(), { 4,5,6,7 })) << endl;
    for (auto i : v1) cout << i << " ";
    return 0;
}