#include <memory>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


using namespace std;

class QueryResult {

	friend void print(ostream&, const QueryResult&);

public:
	QueryResult(const string &word):word(word){}
	QueryResult(const string &word, shared_ptr<vector<string>> text,
		shared_ptr<set<unsigned>> line_num) :
		word(word), text(text), line_num(line_num) {}
private:
	string word;
	shared_ptr<vector<string>> text;
	shared_ptr<set<unsigned>> line_num;
};

class TextQuery {
public:
	TextQuery(ifstream &);
	QueryResult query(const string& s);
private:
	shared_ptr<vector<string>> text;
	map<string, shared_ptr<set<unsigned>>> words;
};


TextQuery::TextQuery(ifstream &infile):
	text(new vector<string>)
{
	string line;
	unsigned line_count=0;
	while (getline(infile, line)) {
		//if (line.empty()) continue;
		text->push_back(line);
		istringstream ss(line);
		string word;
		while (ss >> word) {
			if (words.find(word) == words.cend())
				words[word] = make_shared<set<unsigned>>();
			words[word]->insert(line_count);
		}
		++line_count;
	}
}

QueryResult TextQuery::query(const string &word)
{
	if (words.find(word) != words.cend())
		return QueryResult(word, text, words[word]);
	else
		return QueryResult(word);
}

void print(ostream &out, const QueryResult &q)
{
	if (q.line_num) {
		out << q.word << " occurs " << q.line_num->size()
			<< (q.line_num->size() > 1 ? " times" : " time") << endl;
		for (auto i : *q.line_num)
			out << "\t(line " << i << ") " << (*q.text)[i] << endl;
	} else {
		out << q.word << " not found" << endl;
	}
}

int main()
{
	ifstream in("poem.txt");
	TextQuery tq(in);
	print(cout, tq.query("her"));
	print(cout, tq.query("guo"));
	return 0;
}