#include <iostream>
using std::cout;

int main()
{
    unsigned char c = 0x71;
    cout << (~c<<6);
    return 0;
}