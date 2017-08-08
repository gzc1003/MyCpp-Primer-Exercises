#include <iostream>
extern const int a = 1;
int j = 1;

int main()
{
    extern int helper(void);
    helper();

    int b = 2;
    const int a = 1, *pa = &b;
    //*pa = *pa + 1;

    const int *p1=nullptr;
    const double c = 3.14, *p2 = &c;
    //p1 = p2;

    constexpr const int *p = &j;
    constexpr int q = a;

    return 0;
}