#include <string>
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
using namespace std::placeholders;

bool is_shorter_or_equal(const string &word, size_t sz)
{
	return word.size() <= sz;
}

int main()
{
	vector<string> svec{ "hello", "world", "longerthan6", "hhh" };
	auto f = bind(is_shorter_or_equal, _1, 6);
	cout << count_if(svec.begin(), svec.end(), f) << endl;
}