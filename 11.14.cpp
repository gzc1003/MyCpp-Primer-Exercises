#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <utility>

using std::map; using std::vector;
using std::string;
using std::cout; using std::endl;
using std::pair;

void add_family(map<string, vector<pair<string, string>>> &families, const string &family_name)
{
	families[family_name] = vector<pair<string, string>>();
}

void add_child(map<string, vector<pair<string, string>>> &families, const string &family_name,
	const string &first_name, const string &birthday)
{
	families[family_name].push_back({ first_name, birthday });
}


int main()
{
	map<string, vector<pair<string, string>>> families;
	add_family(families, "GUO");
	add_child(families, "GUO", "Zichun", "10.3");
	add_child(families, "GUO", "Chenhua", "9.6");
	add_child(families, "HOU", "Jun", "5.3");
	for (const auto &f : families) {
		cout << "family " << f.first << ": ";
		for (const auto &child : f.second)
			cout << child.first << "," << child.second << " ";
		cout << endl;
	}

}

