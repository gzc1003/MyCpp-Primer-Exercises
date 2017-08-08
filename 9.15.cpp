#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;


int main()
{
    vector<int> v1 = { 0,1,2,3,4 };
    vector<int> v2 = { 0,1,2 };
    if (v1 == v2)
        cout << "v1 == v2" << endl;
    else
        cout << "v1 != v2" << endl;
    return 0;
}