#include <iostream>
using std::cout; using std::endl;
#include <forward_list>
using std::forward_list;

int main()
{
    forward_list<int> flst = { 1,2,3,4,5,6,7,8,9 };
    for (auto curr = flst.begin(), prev = flst.before_begin();
        curr != flst.end();) {
        if (*curr % 2) {
            flst.insert_after(prev, *curr);
            prev = curr;
            ++curr;
        } else
            curr = flst.erase_after(prev);
    }
    for (auto i : flst)
        cout << i << " ";
    cout << endl;
    return 0;
}