#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout; using std::endl; using std::cin;

void add_word(vector<string> &vec, const string word)
{
	if (std::find(vec.begin(), vec.end(), word) == vec.end())
		vec.push_back(word);
}


int main()
{
	vector<string> words;
	string s;
	while (cin >> s)
		add_word(words, s);
	for (auto &t : words)
		cout << t << " ";
	cout << endl;
	return 0;
}