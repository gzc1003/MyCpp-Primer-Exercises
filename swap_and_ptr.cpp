#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <array>
using std::array;

int main()
{
    vector<int> v1 = { 0,1,2,3,4 };
    vector<int> v2 = { 5,6,7,8,9 };
    int *p = &v1[2];
    cout << "*p = " << *p << endl;
    swap(v1, v2);
    cout << "*p = " << *p << endl;
    
    
    array<int, 5> a1{ 0,1,2,3,4 };    
    array<int, 5> a2{ 5,6,7,8,9 };
    int *pa = &a1[2];
    cout << "*pa = " << *pa << endl;
    swap(a1, a2);
    cout << "*pa = " << *pa << endl;

    cout << v1.size() << endl;
    cout << v1.max_size() << endl;
    return 0;
}