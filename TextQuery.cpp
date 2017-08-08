#include "TextQuery.h"
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

string TextQuery::clearnup_str(const string s) const
{
	string word;
	for (auto beg = s.begin(); beg != s.end(); ++beg)
		if (!ispunct(*beg))
			word += tolower(*beg);
	return word;
}


TextQuery::TextQuery(std::ifstream &input):
	file(new vector<string>)
{
	string line;
	
	for (std::size_t i = 0; getline(input, line); ++i) {
		file->push_back(line);
		istringstream ss(line);
		
		string word;
		while (ss >> word) {
			word = clearnup_str(word);
			if (word_to_lineno.find(word) == word_to_lineno.end())
				word_to_lineno[word] = make_shared<set<size_t>>();
			
			word_to_lineno[word]->insert(i);
		}
	}
	
}

QueryResult TextQuery::query(const string &word) const
{
	auto p = word_to_lineno.find(clearnup_str(word));
	if (p != word_to_lineno.end()) {
		return QueryResult(word, p->second, file);
	} else {
		static shared_ptr<set<size_t>> empty_p(new set<size_t>);
		return QueryResult(word, empty_p, file);
	}
}


std::ostream& operator<<(std::ostream &os, const QueryResult &qr)
{
	os << qr.word<<" occurs " << qr.lineno->size() << " times" << endl;
	for (auto i : *qr.lineno) {
		os << "\t" << "(line " << i + 1 << ") " << (*qr.file)[i] << endl;
	}
	return os;
}


