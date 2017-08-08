#pragma once
#include <string>
#include <iostream>

class SalesData {
	friend std::ostream &operator<<(std::ostream&, const SalesData&);
	friend std::istream &operator>>(std::istream&, SalesData&);
	friend SalesData operator+(const SalesData&, const SalesData&);
	friend bool operator==(const SalesData&, const SalesData&);
public:
	explicit SalesData(const std::string &s = "") :
		book_no(s) { }
	SalesData(const std::string &s, unsigned n, double price) :
		book_no(s), units_sold(n), revenue(n*price) { }
	explicit SalesData(std::istream &is) { is >> *this; }

	SalesData &operator=(const std::string&);
	SalesData &operator+=(const SalesData&);


	std::string isbn() const { return book_no; }
private:
	double average_price() const { return units_sold ? revenue / units_sold : 0; }
	std::string book_no;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

SalesData& SalesData::operator=(const std::string &isbn)
{
	*this = SalesData(isbn);
	return *this;
}


SalesData& SalesData::operator+=(const SalesData &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

SalesData operator+(const SalesData &lhs, const SalesData &rhs)
{
	SalesData sum = lhs;
	sum += rhs;
	return sum;
}

std::ostream &operator<<(std::ostream &out, const SalesData &rhs)
{
	out << rhs.isbn() << " " << rhs.units_sold << " "
		<< rhs.revenue << " " << rhs.average_price();
	return out;
}

std::istream &operator >> (std::istream &in, SalesData &rhs)
{
	double price;
	in >> rhs.book_no >> rhs.units_sold >> price;
	if (in)
		rhs.revenue = rhs.units_sold * price;
	else
		rhs = SalesData();
	return in;
}

bool operator==(const SalesData &lhs, const SalesData &rhs)
{
	return lhs.book_no == rhs.book_no &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}