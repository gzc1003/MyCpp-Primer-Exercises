#ifndef SALESDATA_H
#define SALESDATA_H

#include <string>
#include <iostream>

class SalesData;
SalesData add(const SalesData&, const SalesData&);
std::istream &read(std::istream&, SalesData&);
std::ostream &print(std::ostream&, const SalesData&);


class SalesData {
    friend SalesData add(const SalesData&, const SalesData&);
    friend std::istream &read(std::istream&, SalesData&);
    friend std::ostream &print(std::ostream&, const SalesData&);
public:
    SalesData(const std::string &s, unsigned n, double price) :
        book_no(s), units_sold(n), revenue(n*price)
    {
    
        //std::cout << "constructor SalesData(const std::string &s, unsigned n, double price)" << std::endl;
    }

    //delegating constructor
    SalesData() : SalesData("", 0, 0) { /*std::cout << "delegating constructor SalesData()" << std::endl;*/ }
    SalesData(std::string s) : SalesData(s, 0, 0)
    {
        //std::cout << "delegating constructor SalesData(std::string s)" << std::endl;
    }
    SalesData(std::istream &is) : SalesData()
    {
        //std::cout << "delegating constructor SalesData(std::istream &is)" << std::endl;
        read(is, *this);
    }

    std::string isbn() const { return book_no; }
    SalesData &combine(const SalesData &rhs);
private:
    double average_price() const;
    std::string book_no;
    unsigned units_sold = 0;
    double revenue = 0.0;
};


SalesData& SalesData::combine(const SalesData &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline
double SalesData::average_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}
#endif