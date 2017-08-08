#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;
using std::stoi;

struct Date {
    
    Date() = default;
    Date(const string &);
    unsigned year=0, month=0, day=0;
};

inline 
Date::Date(const string &date)
{
    string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (date.find_first_of(alphabet) != date.npos) {
        if (date.find("Jan") != date.npos) month = 1;
        if (date.find("Feb") != date.npos) month = 2;
        if (date.find("Mar") != date.npos) month = 3;
        if (date.find("Apr") != date.npos) month = 4;
        if (date.find("May") != date.npos) month = 5;
        if (date.find("Jun") != date.npos) month = 6;
        if (date.find("Jul") != date.npos) month = 7;
        if (date.find("Aug") != date.npos) month = 8;
        if (date.find("Sep") != date.npos) month = 9;
        if (date.find("Oct") != date.npos) month = 10;
        if (date.find("Nov") != date.npos) month = 11;
        if (date.find("Dec") != date.npos) month = 12;

        auto i = date.find_first_of("012345678");
        day = stoi(date.substr(i));
        year = stoi(date.substr(date.find_first_of("012345678", i + 1)));
    } else {
        size_t foo=1, *p = &foo;
        month = stoi(date, p);
        string sub_date = date.substr(*p + 1);
        day = stoi(sub_date, p);
        year = stoi(sub_date.substr(*p + 1), p);
    }
}


int main()
{
    Date d1("1/2/1990"), d2("January 2, 1900"), d3("Jan 2 1900"),
        d4("Jan 2, 1990");
    cout << d1.year << "." << d1.month << "." << d1.day << endl;
    cout << d2.year << "." << d2.month << "." << d2.day << endl;
    cout << d3.year << "." << d3.month << "." << d3.day << endl;
    cout << d4.year << "." << d4.month << "." << d4.day << endl;
    return 0;
}