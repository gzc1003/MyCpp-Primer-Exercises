#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;
using namespace std::placeholders;

void eliminate_dups(vector<string> words)
{
	sort(words.begin(), words.end());
	auto unique_end = unique(words.begin(), words.end());
	words.erase(unique_end, words.end());
}


bool check_size(const string &s, size_t sz)
{
	return s.size() >= sz;
}


void biggies(vector<string> &words, size_t sz)
{
	eliminate_dups(words);
	stable_sort(words.begin(), words.end(),
		[](const string &lhs, const string &rhs) {return lhs.size() < rhs.size(); });
	auto check = bind(check_size, _1, sz);

	auto iter = find_if(words.begin(), words.end(), check);
	cout << words.end() - iter << " words more than " << sz << endl;
	for_each(iter, words.end(), [](const string&s) {cout << s << " "; });
	cout << endl;

}

int main()
{
	vector<string> svec{ "aa", "bbb", "eeeee", "cccccc", "dsfasf", "sdf" };
	biggies(svec, 4);
}