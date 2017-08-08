#pragma once

#include <map>
#include <set>
#include <vector>
#include <string>
#include <memory>
#include <fstream>
#include <iostream>

class QueryResult;

class TextQuery {
public:
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string,
		std::shared_ptr<std::set<std::size_t>>> word_to_lineno;
	std::string clearnup_str(std::string) const;
};


class QueryResult {
	friend std::ostream& operator<<(std::ostream&, const QueryResult&);
public: 
	using iterator = std::set<std::size_t>::iterator;
	QueryResult(const std::string &s, std::shared_ptr<std::set<std::size_t>> l,
		std::shared_ptr<std::vector<std::string>> f):
		word(s), lineno(l), file(f) {}
	iterator begin() { return lineno->begin(); }
	iterator end() { return lineno->end(); }

	std::shared_ptr<std::vector<std::string>> get_file() const { return file; }
private:
	std::string word;
	std::shared_ptr<std::set<std::size_t>> lineno;
	std::shared_ptr<std::vector<std::string>> file;
};

std::ostream& operator<<(std::ostream&, const QueryResult&);
