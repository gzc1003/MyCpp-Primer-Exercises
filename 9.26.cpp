#include <list>
using std::list;
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include <iterator>

int main()
{
    int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
    vector<int> v1(std::begin(ia), std::end(ia));
    list<int> l1(std::begin(ia), std::end(ia));

    auto iter1 = v1.begin();
    while (iter1 != v1.end()) {
        if (*iter1 % 2 == 0)
            iter1 = v1.erase(iter1);
        else
            ++iter1;
    }

    auto iter2 = l1.begin();
    while (iter2 != l1.end()) {
        if (*iter2 % 2)
            iter2 = l1.erase(iter2);
        else
            ++iter2;
    }

    for (auto i : v1)
        cout << i << " ";
    cout << endl;

    for (auto i : l1)
        cout << i << " ";
    cout << endl;
    return 0;
}