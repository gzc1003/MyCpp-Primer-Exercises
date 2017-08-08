#include <vector>
using std::vector;
#include <list>
using std::list;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    vector<int> v1 = { 0,1,2,3,4 };
    vector<int> v2(v1);
    vector<int> v3 = v1;
    vector<int> v4(v1.begin(), v2.end());
    vector<int> v5(5);
    vector<int> v6(5, 1);
    
    //9.13
    list<int> l1 = { 0,1,2,3,4 };
    vector<double> v7(l1.begin(), l1.end());
    for (auto i : l1) cout << i << ' ';
    cout << endl;
    for (auto i : v7) cout << i << ' ';
    cout << endl;

    vector<double> v8(v1.begin(), v1.end());
    for (auto i : v1) cout << i << ' ';
    cout << endl;
    for (auto i : v8) cout << i << ' ';
    cout << endl;

    return 0;
}