#include <iostream>
#include "Sales_item.h"
using namespace std;

int main()
{
    Sales_item total;
    if (cin >> total) {
        Sales_item trans;
        while (cin >> trans) {
            if (trans.isbn() == total.isbn())
                total += trans;
            else {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    }
    else {
        cerr << "No input data!" << endl;
        return -1;
    }
    return 0;
}