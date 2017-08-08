#include <map>
using std::map;
#include <iostream>
using std::cout; using std::endl;

int main()
{
	map<int, int> m = { {0,0} };
	map<int, int>::iterator iter = m.begin();
	iter->second = 2;
	
	for (const auto &p : m)
		cout << p.first << " " << p.second;
	cout << endl;

	return 0;
}