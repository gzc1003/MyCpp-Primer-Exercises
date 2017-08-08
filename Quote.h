#pragma once
#include <string>

class Quote {
public:
	Quote() = default;
	Quote(const Quote &q) = default;
	Quote(Quote &&q) = default;
	Quote &operator=(const Quote &rhs) = default;
	Quote &operator=(Quote &&rhs) = default;
	virtual ~Quote() =default;

	Quote(const std::string &s, double p) : bookNo(s), price(p) {}
	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const { return n*price; }
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && {return new Quote(std::move(*this)); }


private:
	std::string bookNo;
protected:
	double price = 0.0;
};


class DiscQuote : public Quote {
public:
	DiscQuote() = default;
	DiscQuote(const DiscQuote&) = default;
	DiscQuote(DiscQuote &&) = default;
	DiscQuote &operator=(const DiscQuote &rhs) = default;
	DiscQuote &operator=(DiscQuote &&rhs) = default;

	DiscQuote(const std::string &s, double p, std::size_t m, double d) :
		Quote(s, p), qty(m), discount(d) {}
	double net_price(std::size_t) const = 0;
protected:
	std::size_t qty = 0;
	double discount = 0.0;
};


class BulkQuote : public DiscQuote {
public:
	BulkQuote() = default;
	BulkQuote(const BulkQuote &q) = default;
	BulkQuote(BulkQuote &&q) = default;
	BulkQuote &operator=(const BulkQuote &rhs) = default;
	BulkQuote &operator=(BulkQuote &&rhs) = default;

	using DiscQuote::DiscQuote;

	double net_price(std::size_t) const override;
	BulkQuote* clone() const & override { return new BulkQuote(*this); }
	BulkQuote* clone() && override {return new BulkQuote(std::move(*this)); }
};

inline 
double BulkQuote::net_price(std::size_t n) const
{
	if (n < qty)
		return n * price;
	else
		return n*price*(1 - discount);
}

double print_total(std::ostream &os, const Quote &item, std::size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}