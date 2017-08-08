#include "7.41.h"
#include <iostream>
using std::cin;
using std::istream; using std::ostream;

int main()
{
    SalesData sd1;
    SalesData sd2("9-9-9");
    SalesData sd3(cin);
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
