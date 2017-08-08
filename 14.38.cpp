#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <iostream>

using namespace std;

class CheckStr {
public:
	bool operator()(const std::string &s, size_t size)
	{
		return s.size() == size;
	}
};



int main()
{
	vector<CheckStr> predicates;
	for (auto i = 1; i != 11; ++i)
		predicates.push_back(CheckStr());
	ifstream input("test.txt");
	string word;

	map<size_t, size_t> words_count;

	while (input >> word) {
		for (auto i = 1; i != 11; ++i) {
			auto predicate = predicates[i];
			if (predicate(word, i))
				++words_count[i];
		}	
	}

	for (auto p : words_count)
		cout << "length: " << p.first << " count: "
		<< p.second << endl;
}