#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>


using std::map;
using std::string;
using std::istringstream;
using std::ifstream;
using std::cout; using std::endl;

using Map = map<string, string>;

Map build_map(ifstream &input_file)
{
	Map word_map;
	string key, line;
	while (input_file >> key && std::getline(input_file, line)) {
		string::size_type pos;
		if ((pos = line.find_first_not_of(' ')) != string::npos)
			word_map[key] = line.substr(pos);
		else
			throw std::runtime_error("bad format, no value.");
	}
	return word_map;
}

const string& transform(const Map &m, string &s)
{
	if (m.find(s) != m.cend())
		return m.at(s);
	else
		return s;
}


void word_transform(ifstream &rule, ifstream &target)
{
	Map word_map = build_map(rule);
	string line;
	while (std::getline(target, line)) {
		istringstream is(line);
		string word;
		bool firstword = true;
		while (is >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word_map, word);
		}
		cout << endl;
	}
}



int main()
{
	word_transform(ifstream("rules"), ifstream("text"));
}