#include <vector>
using std::vector;
#include <iterator>
using std::begin; using std::end;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    int array[] = { 0,1,2,3,4,5 };
    vector<int> v(begin(array), end(array));

    for (auto n : v)
        cout << n << " ";
    cout << endl;
    
    int array2[6];
    for (int i = 0; i != v.size(); ++i)
        array2[i] = v[i];

    for (auto n:array2)
        cout << n << " ";
    cout << endl;
    return 0;
}