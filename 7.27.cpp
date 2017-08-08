#include "7.27.h"
#include <iostream>
using std::cout;

int main()
{
    Screen my_screen(5, 5, 'X');
    my_screen.move(4, 0).set('#').display(cout);
    cout << "\n";
    my_screen.display(cout);
    cout << "\n";
    return 0;
}