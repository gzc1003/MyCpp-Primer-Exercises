#include <map>
#include <string>
#include <vector>
#include <iostream>

using std::multimap;
using std::string;
using std::vector;
using std::cin; using std::cout; using std::endl;

class Family
{
public:
	using Fam = multimap<string, string>;
	void add_child(const string &first_name, const string &last_name)
	{
		_data.emplace(first_name, last_name);
	}
	void print() 
	{
		for (const auto &p : _data)
			cout << p.first << " " << p.second << endl;
	}
private:
	Fam _data;
};

int main()
{
	Family f;
	string first_name, last_name;
	while (cin >> first_name >> last_name)
		f.add_child(first_name, last_name);
	f.print();
	return 0;
}
