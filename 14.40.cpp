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



class CheckSize {
public:
	CheckSize(size_t n) : sz(n) {};
	bool operator()(const string &s) const
	{
		return s.size() >= sz;
	}
private:
	size_t sz;
};



void biggies(vector<string> &words, size_t sz)
{
	eliminate_dups(words);
	stable_sort(words.begin(), words.end(),
		[](const string &lhs, const string &rhs) {return lhs.size() < rhs.size(); });
	
	CheckSize check(sz);

	auto iter = stable_partition(words.begin(), words.end(), check);
	cout << iter - words.begin() << " words more than " << sz << endl;
	for_each(words.begin(), iter, [](const string&s) {cout << s << " "; });
	cout << endl;

}

int main()
{
	vector<string> svec{ "aa", "bbb", "eeeee", "cccccc", "dsfasf", "sdf" };
	biggies(svec, 4);
}