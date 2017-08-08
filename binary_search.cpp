#include <vector>
using std::vector;

#include <iostream>
using std::cout; using std::cin; using std::endl;

int main()
{
    int sought = 76;
    vector<int> integers_in_order{ 2,5,12,35,36,60,60,75,90,100 };
    auto beg = integers_in_order.begin(), end = integers_in_order.end();
    auto mid = beg + (end - beg) / 2;
    while (beg != end && *mid != sought) {
        if (*mid < sought)
            beg = mid + 1;
        else
            end = mid;
        mid = beg + (end - beg) / 2;
    }
    if (*mid == sought)
        cout << true << endl;
    else
        cout << false << endl;
    return 0;
}