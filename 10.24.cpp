#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, size_t sz)
{
	return s.size() >= sz;
}

int main()
{
	vector<int> vec{ 3,5,1,6,3,5,8 };
	string s("word");
	auto iter = find_if_not(vec.begin(), vec.end(), bind(check_size, s, _1));
	if (iter != vec.end())
		cout << *iter << endl;
	else
		cout << "not found" << endl;
}