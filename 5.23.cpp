#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <stdexcept>
using std::runtime_error;

int main()
{
    int a, b;
    while (cin >> a >> b) {
        try {
            if (b == 0)
                throw runtime_error("divisor can not be zero");
            cout << a / b << endl;
        } catch (runtime_error err) {
            cout << err.what() << "\nTry again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;
        }
    }
    return 0;
}