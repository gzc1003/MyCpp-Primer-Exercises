#include <cstddef>
#include <iostream>
using std::cout; using std::endl;

int main()
{
    int array[10], copy_array[10];
    for (size_t i = 0; i < 10; ++i)
        array[i] = i;
    for (auto i : array)
        cout << i << " ";
    cout << endl;
    return 0;
}