#include <string>
#include <iostream>

class Quote {
public:
	Quote() = default;
	Quote(const std::string &s, double p) : bookNo(s), price(p) {}
	virtual ~Quote() = default;
	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n*price; }
	virtual void debug() const
	{
		std::cout << "bookNo: " << isbn()
			<< " price: " << price;
	}
private:
	std::string bookNo;
protected:
	double price = 0.0;
};


class DiscQuote : public Quote {
public:
	DiscQuote() = default;
	DiscQuote(const std::string &s, double p, std::size_t m, double d) :
		Quote(s,p), qty(m), discount(d) {}
	double net_price(std::size_t) const = 0;
protected:
	std::size_t qty = 0;
	double discount = 0.0;
};


class BulkQuote : public DiscQuote {
public:
	BulkQuote() = default;
	BulkQuote(const std::string &s, double p, std::size_t m, double d)
		: DiscQuote(s,p,m,d) {}
	double net_price(std::size_t) const override;
};


double BulkQuote::net_price(std::size_t n) const
{
	if (n < qty)
		return n * price;
	else
		return n*price*(1 - discount);
}

class LimitQuote : DiscQuote {
public:
	LimitQuote() = default;
	LimitQuote(const std::string &s, double p, std::size_t m, double d)
		: DiscQuote(s, p, m, d) {}
	double net_price(std::size_t) const override;
};

double LimitQuote::net_price(std::size_t n) const
{
	if (n <= qty)
		return n*price*(1 - discount);
	else
		return (n - qty)*price + qty*price*(1 - discount);
}


double print_total(std::ostream &os, const Quote &q, std::size_t n)
{
	double ret = q.net_price(n);
	os << "ISBN: " << q.isbn() << " # sold: "
		<< n << " total price " << ret << std::endl;
	return ret;
}

void print_debug(const Quote &item)
{
	item.debug();
	std::cout << std::endl;
}

int main()
{
	BulkQuote b("12345", 3.14, 8, 0.2);
	print_debug(b);
	print_total(std::cout, b, 10);

	Quote b2 = b;
	print_debug(b2);
	print_total(std::cout, b2, 10);
}