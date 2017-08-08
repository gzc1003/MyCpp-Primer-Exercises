#include <iterator>
using std::begin; using std::end;
#include <iostream>
using std::cout; using std::endl;


bool compare_array(int *beg1, int *end1, int *beg2, int *end2)
{
    if (end1 - beg1 != end2 - beg2)
        return false;
    else {
        for (; beg1 != end1; ++beg1, ++beg2)
            if (*beg1 != *beg2)
                return false;
        return true;
    }
}

int main()
{
    int arr1[] = { 1, 2, 3 }, arr2[] = { 1,2,3 };
    cout << compare_array(begin(arr1), end(arr1), begin(arr2), end(arr2))
        << endl;

    return 0;
}