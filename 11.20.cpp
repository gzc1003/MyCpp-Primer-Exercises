#include <map>
#include <string>
#include <iostream>

using std::map;
using std::string;
using std::cout; using std::endl; using std::cin;

int main()
{
	map<string, std::size_t> word_count;
	string word;
	while (cin >> word) 
		++word_count.insert({ word, 0 }).first->second;
	for (const auto &p : word_count)
		cout << p.first << " " << p.second << endl;
	return 0;
}