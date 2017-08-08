#include <map>
#include <string>
#include <iostream>
#include <set>

using std::multiset;
using std::map;
using std::multimap;
using std::string;
using std::cout; using std::endl;

void del(multimap<string, string> &m, const string &author,
	const string &book)
{
	auto entries = m.count(author);
	auto iter = m.find(author);
	while (entries) {
		if (iter->second == book) {
			m.erase(iter);
			break;
		}
		--entries;
		++iter;
	}
}


int main()
{
	multimap<string, string> authors{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency" }
	};
	del(authors, "alan", "DMA");
	del(authors, "pezy", "book2");
	del(authors, "guo", "book1");

	map<string, multiset<string>> ordered_authors;
	for (const auto &p : authors)
		ordered_authors[p.first].insert(p.second);
	for (const auto &p : ordered_authors) {
		cout << p.first << ": ";
		for (const auto &s : p.second)
			cout << s << " ";
		cout << endl;
	}
	return 0;
}