#include <iterator>
using std::begin; using std::end;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    int array[10];
    int *pbeg = begin(array), *pend = end(array);
    while (pbeg != pend) {
        *pbeg = 0;
        ++pbeg;
    }
    for (auto i : array)
        cout << i << " ";
    cout << endl;
    return 0;
}