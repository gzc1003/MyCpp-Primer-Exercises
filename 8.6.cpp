#include <string>
using std::string;
#include <iostream>
using std::istream; using std::ostream;
using std::cin; using std::cout; using std::endl; using std::cerr;
#include <fstream>
using std::ifstream; using std::ofstream;



struct SalesData {

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

int main(int argc, char *argv[])
{
    SalesData total;
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    if (input) {
        if (read(input, total)) {
            SalesData trans;
            while (read(input, trans)) {
                if (trans.isbn() == total.isbn()) {
                    total.combine(trans);
                } else {
                    print(output, total) << endl;
                    total = trans;
                }
            }
            print(output, total) << endl;
        } else {
            cerr << "No data" << endl;
            return -1;
        }
    }
    return 0;
}