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
			<< " price: " << price << std::endl;
	}
private:
	std::string bookNo;
protected:
	double price = 0.0;
};


class BulkQuote : public Quote {
public:
	BulkQuote() = default;
	BulkQuote(const std::string &s, double p, std::size_t m, double d)
		:Quote(s, p), min_qty(m), discount(d) {}
	double net_price(std::size_t) const override;
	void debug() const override
	{
		std::cout << "bookNo: " << isbn()
			<< " price: " << price << " min_qty: " << min_qty
			<< " discount: " << discount << std::endl;
	}

private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

double BulkQuote::net_price(std::size_t n) const
{
	if (n < min_qty)
		return n * price;
	else
		return n*price*(1 - discount);
}




double print_total(std::ostream &os, const Quote &q, std::size_t n)
{
	double ret = q.net_price(n);
	os << "ISBN: " << q.isbn() << " # sold: "
		<< n << " total price " << ret << std::endl;
	return ret;
}

int main()
{
	BulkQuote b("12345", 3.14, 8, 0.2);
	b.debug();
	print_total(std::cout, b, 10);

	Quote b2 = b;
	b2.debug();
	print_total(std::cout, b2, 10);
}