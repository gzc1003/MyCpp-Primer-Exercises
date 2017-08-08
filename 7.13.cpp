#include <string>
using std::string;
#include <iostream>
using std::istream; using std::ostream;
using std::cin; using std::cout; using std::endl; using std::cerr;

struct SalesData;
istream& read(istream&, SalesData&);


struct SalesData {

    SalesData() = default;
    SalesData(istream &is) { read(is, *this); }
    SalesData(const string &s, unsigned n, double price) :
        book_no(s), units_sold(n), revenue(n*price) { }
    SalesData(const string &s) :
        book_no(s) { }

    string isbn() const { return book_no; }
    SalesData &combine(const SalesData &rhs);
    double average_price() const;
    string book_no;
    unsigned units_sold = 0;
    double revenue = 0.0;

};


SalesData& SalesData::combine(const SalesData &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

double SalesData::average_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
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