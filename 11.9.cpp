#include <map>
#include <string>
#include <list>
#include "7.41.h"
#include <set>

using std::map;
using std::string;
using std::list;

map<string, list<unsigned>> words;

typedef bool comp(const SalesData&, const SalesData&);

bool compareIsbn(const SalesData &lhs, const SalesData &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

std::multiset<SalesData, comp*> bookstore(compareIsbn);