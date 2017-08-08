#include "7.41.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

inline
bool compareIsbn(const SalesData &d1, const SalesData &d2)
{
    return d1.isbn() < d2.isbn();
}

std::istream &read(std::istream &is, SalesData &d)
{
    double price = 0.0;
    is >> d.book_no >> d.units_sold >> price;
    d.revenue = d.units_sold * price;
    return is;
}

std::ostream& print(std::ostream &os, const SalesData &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue
        << " " << item.average_price();
    return os;
}

int main(int argc, char *argv[])
{   
    std::ifstream input_file(argc > 1 ? argv[1] : "book_sales");
    if (!input_file)
        std::cerr << "fail to open file" << std::endl;

    std::vector<SalesData> vec;
    for (SalesData tmp_d; read(input_file, tmp_d);)
    {
        vec.push_back(tmp_d);
    }

    std::sort(vec.begin(), vec.end(), compareIsbn);
    for (auto &d : vec) {
        print(std::cout, d) << std::endl;
    }
    return 0;
}