#include "SalesData.h"
#include <iostream>
using namespace std;

int main()
{
    SalesData total, current;
    double price = 0.0;
    if (cin >> total.book_number >> total.units_sold >> price) {
        total.revenue = price*total.units_sold;
        while (cin >> current.book_number >> current.units_sold >> price) {
            current.revenue = current.units_sold * price;
            if (current.book_number == total.book_number) {
                total.units_sold += current.units_sold;
                total.revenue += current.revenue;
            } else {
                cout << total.book_number << '\t'
                    << total.units_sold << '\t'
                    << total.revenue << '\t';
                if (total.units_sold != 0)
                    cout << total.revenue / total.units_sold << endl;
                else
                    cout << "no sales" << endl;
                total.book_number = current.book_number;
                total.units_sold = current.units_sold;
                total.revenue = current.revenue;
            }
        }
        cout << total.book_number << '\t'
            << total.units_sold << '\t'
            << total.revenue << '\t';
        if (total.units_sold != 0)
            cout << total.revenue / total.units_sold << endl;
        else
            cout << "no sales" << endl;
        return 0;
    } else {
        cerr << "No input!" << endl;
        return -1;
    }
}