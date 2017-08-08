#include <forward_list>
using std::forward_list;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    forward_list<int> flst = { 1,2,3,4,5,6 };
    auto curr = flst.begin();
    auto prev = flst.before_begin();
    while (curr != flst.end()) {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }
        
    for (auto i : flst)
        cout << i << " ";

    return 0;
}