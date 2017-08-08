#include <string>
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

class isInBound {
	size_t lower_bound;
	size_t upper_bound;
public:
	isInBound(size_t l, size_t u): lower_bound(l), upper_bound(u) {}
	bool operator()(std::string &s) const
	{
		return s.size() <= upper_bound && s.size() >= lower_bound;
	}
};

int main()
{
	ifstream in("test.txt");
	isInBound is_inbound(1u, 9u);
	map<size_t, size_t> words_length;
	for (string word; in >> word; )
		if (is_inbound(word))
			++words_length[9u];
		else
			++words_length[10u];

	for (auto p : words_length)
		cout << "word length " <<p.first << ": "<< p.second << endl;
}