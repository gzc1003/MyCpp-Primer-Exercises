#include <string>
using std::string;
#include <iostream>
using std::istream; using std::ostream;
using std::cin; using std::cout; using std::endl; using std::cerr;
#include "7.21.h"

int main()
{
    SalesData total(cin);
    if (!total.isbn().empty()) {
        SalesData trans(cin);
        while (!trans.isbn().empty()) {
            if (trans.isbn() == total.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
            SalesData tmp(cin);
            trans = tmp;
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data" << endl;
        return -1;
    }
    return 0;
}


SalesData add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;
}


istream& read(istream &is, SalesData &item)
{
    double price = 0.0;
    is >> item.book_no >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream& print(ostream &os, const SalesData &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue
        << " " << item.average_price();
    return os;
}


