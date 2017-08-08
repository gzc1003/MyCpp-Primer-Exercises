#include "Quote.h"
#include <memory>
#include <set>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

class Basket
{
public:
	void add_item(const Quote&);
	void add_item(Quote &&);
	double total_receipt(std::ostream&) const;
private:
	static bool compare(const std::shared_ptr<Quote>, const std::shared_ptr<Quote>);
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

inline
bool Basket::compare(const std::shared_ptr<Quote>lhs, const std::shared_ptr<Quote>rhs)
{
	return lhs->isbn() < rhs->isbn();
}

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;
	for (auto iter = items.begin(); iter != items.end(); iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	return sum;
}

void Basket::add_item(const Quote &q)
{
	items.insert(std::shared_ptr<Quote>(q.clone()));
}

void Basket::add_item(Quote &&q)
{
	items.insert(std::shared_ptr<Quote>(std::move(q).clone()));
}

int main()
{
	Basket basket;
	basket.add_item(BulkQuote("a", 50, 2, 0.25));
	basket.add_item(BulkQuote("b", 50, 2, 0.3));
	basket.add_item(BulkQuote("a", 50, 2, 0.25));
	basket.add_item(BulkQuote("b", 50, 2, 0.3));
	double ret = basket.total_receipt(std::cout);
	std::cout << ret << std::endl;


	std::vector<std::shared_ptr<Quote>> basket2;
	basket2.push_back(std::make_shared<BulkQuote>(BulkQuote("a", 50, 2, 0.25)));
	basket2.push_back(std::make_shared<BulkQuote>(BulkQuote("b", 50, 2, 0.3)));
	basket2.push_back(std::make_shared<BulkQuote>(BulkQuote("a", 50, 2, 0.25)));
	basket2.push_back(std::make_shared<BulkQuote>(BulkQuote("b", 50, 2, 0.3)));
	std::sort(basket2.begin(), basket2.end(),
		[](const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
	{return lhs->isbn() < rhs->isbn(); });
	double sum = 0.0;
	for (auto iter = basket2.begin(); iter != basket2.end(); iter = std::find_if_not(
		iter, basket2.end(), [&iter](const std::shared_ptr<Quote> &sp) {return sp->isbn() == (*iter)->isbn(); }) )
	{
		sum += print_total(std::cout, **iter, std::count_if(basket2.begin(), basket2.end(), 
			[&iter](const std::shared_ptr<Quote> &sp) {return sp->isbn() == (*iter)->isbn(); }));
	}
	std::cout << sum << std::endl;
} 