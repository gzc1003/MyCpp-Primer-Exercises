#include <iostream>
using std::cout; using std::endl;

void swap_pointer(int *&a, int *&b)
{
    int *tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 1, b = 2;
    int *pa = &a, *pb = &b;
    cout << "*pa= " << *pa << " " << "*pb= " << *pb << endl;
    swap_pointer(pa, pb);
    cout << "*pa= " << *pa << " " << "*pb= " << *pb << endl;
    return 0;
}
