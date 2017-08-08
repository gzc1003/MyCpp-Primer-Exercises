#include <vector>
using std::vector;


#include <iostream>
using std::cin; using std::cout; using std::endl;


int main()
{
    vector<int> v1 = { 0,1,2,3,4}, v2 = { 0,1,2};

    vector<int> sht, lng;

    if (v1.size() < v2.size()) {
        sht = v1;
        lng = v2;
    } else {
        sht = v2;
        lng = v1;
    }

    decltype(sht.size()) i = 0;
    for (; i != sht.size(); ++i)
        if (sht[i] != lng[i]) {
            cout << "not prefix" << endl;
            break;
        }
    if (i == sht.size())
        cout << "prefix" << endl;

    return 0;
}