#include <utility>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string s;
	int i = 0;
	vector<pair<string, int>> vec;
	while (cin >> s >> i) {
		pair<string, int> p(s, i);
		// pair<string, int> p = {s, i};
		//vec.push_back(make_pair(s, i));
		vec.push_back(p);
	}
	for (const auto &p : vec)
		cout << p.first << " " << p.second << endl;
	return 0;
}