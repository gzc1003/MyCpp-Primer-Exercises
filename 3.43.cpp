#include <iostream>
using std::cout; using std::endl;


#ifdef RANGE_FOR 
int main()
{
    int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    for (int(&r)[4] : ia)
        for (int n : r)
            cout << n << " ";
    cout << endl;
    return 0;
}
#endif

#ifdef SUBSCRIPT_FOR
#include <cstddef>
using std::size_t;
int main()
{
    int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    for (size_t row=0; row != 3; ++row)
        for (size_t column=0; column != 4; ++column)
            cout << ia[row][column] << " ";
    cout << endl;
    return 0;
}
#endif

#include <iterator>
using std::begin; using std::end;
int main()
{
    int ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
    for (int (*p)[4]=begin(ia); p != end(ia); ++p)
        for (int *q=begin(*p); q!=end(*p); ++q)
            cout << *q << " ";
    cout << endl;
    return 0;
}