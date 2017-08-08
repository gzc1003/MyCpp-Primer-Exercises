#include <list>
using std::list;
#include <deque>
using std::deque;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    list<int> l = { 1,2,3,4,5 };
    deque<int> odd, even;
    for (auto n : l) {
        if (n % 2 == 0)
            even.push_back(n);
        else
            odd.push_back(n);
    }

    for(auto n:odd)
        cout << n << " ";
    cout << endl;
    for (auto n : even)
        cout << n << " ";
    return 0;
}