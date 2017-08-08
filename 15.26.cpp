#include <string>
#include <iostream>
#include <utility>
using std::cout; using std::endl;

class Quote {
public:
	Quote() { cout << "Quote()" << endl; };
	Quote(const Quote &q) : bookNo(q.bookNo), price(q.price)
	{
		cout << "Quote(const Quote&)" << endl;
	}
	Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
	{
		cout << "Quote(Quote &&q)" << endl;
	}
	Quote &operator=(const Quote &rhs)
	{
		bookNo = rhs.bookNo;
		price = rhs.price;
		cout << "Quote &operator=(const Quote &rhs)" << endl;
		return *this;
	}
	Quote &operator=(Quote &&rhs) noexcept
	{
		bookNo = std::move(rhs.bookNo);
		price = std::move(rhs.price);
		cout << "Quote &operator=(Quote &&rhs)" << endl;
		return *this;
	}

	virtual ~Quote() { cout << "~Quote" << endl; };


	Quote(const std::string &s, double p) : bookNo(s), price(p) {}
	std::string isbn() const { return bookNo; }

	virtual double net_price(std::size_t n) const { return n*price; }
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
	BulkQuote() { cout << "BulkQuote()" << endl; }
	BulkQuote(const BulkQuote &q) : DiscQuote(q)
	{
		cout << "BulkQuote(const BulkQuote &q)" << endl;
	}
	BulkQuote(BulkQuote &&q) noexcept :
		DiscQuote(std::move(q))
	{
		cout << "BulkQuote(BulkQuote &&q)" << endl;
	}
	BulkQuote &operator=(const BulkQuote &rhs)
	{
		DiscQuote::operator=(rhs);
		cout << "BulkQuote &operator=(const BulkQuote &rhs)" << endl;
		return *this;
	}
	BulkQuote &operator=(BulkQuote &&rhs) noexcept
	{
		DiscQuote::operator=(std::move(rhs));
		cout << "BulkQuote &operator=(BulkQuote &&rhs)" << endl;
		return *this;
	}
	~BulkQuote() { cout << "~BulkQuote()" << endl; }

	using DiscQuote::DiscQuote;

	double net_price(std::size_t) const override;
};


double BulkQuote::net_price(std::size_t n) const
{
	if (n < qty)
		return n * price;
	else
		return n*price*(1 - discount);
}

int main()
{
	BulkQuote b, b2 = b, b3;
	b3 = std::move(b);
}