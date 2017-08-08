#include <memory>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>


using namespace std;

class DebugDelete {
public:
	DebugDelete(std::ostream &o = std::cerr) : os(o) {}
	template <typename T> void operator()(T *p) const
	{
		os << "delete unique_ptr" << std::endl;
		delete p;
	}
private:
	std::ostream &os;
};

class QueryResult {

	friend void print(ostream&, const QueryResult&);

public:
	QueryResult(const string &word) :word(word) {}
	QueryResult(const string &word, shared_ptr<vector<string>> text,
		shared_ptr<set<unsigned>> line_num) :
		word(word), text(text), line_num(line_num) {}
	shared_ptr<vector<string>> get_file() const { return text; }
	set<unsigned>::iterator begin() const { return line_num->begin(); }
	set<unsigned>::iterator end() const { return line_num->end(); }
private:
	string word;
	shared_ptr<vector<string>> text;
	shared_ptr<set<unsigned>> line_num;
};

class TextQuery {
public:
	TextQuery(ifstream &);
	QueryResult query(const string& s) const;
private:
	shared_ptr<vector<string>> text;
	map<string, shared_ptr<set<unsigned>>> words;
};


TextQuery::TextQuery(ifstream &infile) :
	text(new vector<string>, DebugDelete())
{
	string line;
	unsigned line_count = 0;
	while (getline(infile, line)) {
		text->push_back(line);
		istringstream ss(line);
		string word;
		while (ss >> word) {
			word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
			if (words.find(word) == words.cend())
				words[word] = make_shared<set<unsigned>>();
			words[word]->insert(line_count);
		}
		++line_count;
	}
}

QueryResult TextQuery::query(const string &word) const
{
	auto iter = words.find(word);
	if (iter != words.cend())
		return QueryResult(word, text, iter->second);
	else
		return QueryResult(word);
}

void print(ostream &out, const QueryResult &q)
{
	if (q.line_num) {
		out << q.word << " occurs " << q.line_num->size()
			<< (q.line_num->size() > 1 ? " times" : " time") << endl;
		for (auto i : *q.line_num)
			out << "\t(line " << i + 1 << ") " << (*q.text)[i] << endl;
	} else {
		out << q.word << " not found" << endl;
	}
}

int main()
{
	ifstream in("poem.txt");
	TextQuery tq(in);
	print(cout, tq.query("Ending"));
	print(cout, tq.query("comedy"));
	system("pause");
	return 0;
}

