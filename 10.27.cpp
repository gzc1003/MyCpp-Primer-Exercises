#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>

using std::vector; 
using std::list;
using std::cout; using std::endl;

int main()
{
    vector<int> vec{ 1,1,2,2,4,4};
    list<int> lst;
    auto end_unique = std::unique_copy(vec.begin(), vec.end(), std::back_inserter(lst));
    cout << "vec: ";
    for(auto i:vec) cout << i << " ";
    cout << endl;
    cout << "lst: ";
    for (auto i : lst) cout << i << " ";
    cout << endl;
    
    return 0;
}