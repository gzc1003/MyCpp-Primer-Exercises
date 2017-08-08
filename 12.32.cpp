#include "StrBlob_old_one.h"
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>


class QueryResult;

class TextQuery {
public:
	typedef StrBlob::size_type line_no;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &word) const;
private:
	StrBlob file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> words;
};


class QueryResult {
	friend std::ostream &print(std::ostream &out, const QueryResult &qr);
public:
	QueryResult(const std::string &word,
		const StrBlob &f,
		std::shared_ptr<std::set<TextQuery::line_no>> p) :
		word(word), file(f), lines(p){}
	//此处file(f)调用了合成的拷贝构造函数，将f的成员逐个拷贝到正在创建的对象中
private:
	std::string word;
	StrBlob file;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
};


TextQuery::TextQuery(std::ifstream &in)
{
	std::string line;
	line_no line_num = 0;
	while (std::getline(in, line)) {
		file.push_back(line);
		std::istringstream is(line);
		std::string word;
		
		while (is >> word) {
			word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
			auto &p = words[word];
			if (!p) p.reset(new std::set<line_no>);
			words[word]->insert(line_num);
		}
		
		++line_num;
	}
}


QueryResult TextQuery::query(const std::string &word) const
{
	auto p = words.find(word);
	if (p != words.end())
		return QueryResult(word, file, p->second);
	else {
		static std::shared_ptr<std::set<line_no>> empty_set_ptr(new std::set<line_no>);
		return QueryResult(word, file, empty_set_ptr);
	}
}

std::ostream &print(std::ostream &out, const QueryResult &qr)
{
	out << qr.word << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() > 1 ? "times" : "time") << std::endl;
	for (auto i : *qr.lines) {
		out << "\t(line " << i + 1 << ") " << *(qr.file.begin()+i) << std::endl;
	}
	return out;
}

int main()
{
	std::ifstream in("poem.txt");
	TextQuery tq(in);
	print(std::cout, tq.query("Ending"));
	print(std::cout, tq.query("comedy"));
	system("pause");
	return 0;
}