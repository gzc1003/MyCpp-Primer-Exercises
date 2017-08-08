#ifndef SALESDATA_H
#define SALESDATA_H
#include <string>
struct SalesData {
    std::string book_number;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif