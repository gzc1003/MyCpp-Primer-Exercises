#include <vector>
using std::vector;
#include <list>
using std::list;
#include <iostream>
using std::cout; using std::endl;

bool is_equal(vector<int> &v, list<int> &l)
{
    if (v.size() != l.size())
        return false;
    else {
        auto iterv = v.cbegin();
        auto iterl = l.cbegin();
        for (; iterv != v.cend() && iterl != l.cend(); ++iterv, ++iterl)
            if (*iterv != *iterl)
                return false;
        return true;
    }
}


int main()
{
    vector<int> v1{ 1,2,3,4,5 };
    list<int> l1{ 1,2,3,4,5 };
    cout << (is_equal(v1, l1) ? "equal" : "not equal") << endl;

    cout << (vector<int>(l1.begin(), l1.end()) == v1 ? "equal" : "not equal") << endl;
    
    vector<int> tmp;
    tmp.assign(l1.begin(), l1.end());
    cout << (tmp == v1 ? "equal" : "not equal") << endl;
    return 0;
}

