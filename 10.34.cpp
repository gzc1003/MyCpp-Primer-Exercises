#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <list>

using std::vector;
using std::cout; using std::endl;

int main()
{
    vector<int> vec{ 1,2,3,4,5,6,7,0,8,9,10};
    for (auto rbeg = vec.crbegin(); rbeg != vec.crend(); ++rbeg)
        cout << *rbeg << " ";
    cout << endl;

    for (auto end = vec.end() - 1; end >= vec.begin(); --end)
        cout << *end << " ";
    cout << endl;

    auto iter = std::find(vec.crbegin(), vec.crend(), 0);
    cout << vec.cend() - (iter.base()-1)<< endl;
    cout << iter - vec.crbegin() << endl;

    std::list<int> lst;
    std::copy(vec.crbegin() + 3, vec.crbegin() + 8, std::back_inserter(lst));
    for (auto i : lst) cout << i << " ";
    cout << endl;
    return 0;
}