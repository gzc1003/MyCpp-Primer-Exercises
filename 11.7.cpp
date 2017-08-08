#include <map>
#include <vector>
#include <string>
#include <iostream>

using std::map; using std::vector;
using std::string;
using std::cout; using std::endl;

void add_family(map<string, vector<string>> &families, const string &family_name)
{
	families[family_name] = vector<string>();
}

void add_child(map<string, vector<string>> &families, const string &family_name,
	const string &first_name)
{
	families[family_name].push_back(first_name);
}


int main()
{
	map<string, vector<string>> families;
	add_family(families, "GUO");
	add_child(families, "GUO", "Zichun");
	add_child(families, "GUO", "Chenhua");
	add_child(families, "HOU", "Jun");
	for (const auto &f : families) {
		cout << "family " << f.first << ": ";
		for (const auto &child : f.second)
			cout << child << " ";
		cout << endl;
	}

}

