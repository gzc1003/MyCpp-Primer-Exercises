#include <string>
#include <memory>
#include "TextQuery.h"
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

class QueryBase {
	friend class Query;
protected:
	virtual ~QueryBase() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual string rep() const = 0;
	
};


class Query {
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
	friend ostream& operator<<(ostream&, const Query&);
public:
	Query(const string &s);
	QueryResult eval(const TextQuery &t) const { return p->eval(t); };
	string rep() const { return p->rep(); };
private:
	Query(shared_ptr<QueryBase> q) :p(q) {};
	shared_ptr<QueryBase> p;
};

ostream& operator<<(ostream &os, const Query &q)
{
	cout << q.rep();
	return os;
}


class WordQuery : public QueryBase {
	friend class Query;
	WordQuery(const string &s) : query_word(s) {}
	QueryResult eval(const TextQuery &tq) const override { return tq.query(query_word); };
	string rep() const override { return query_word; };
	string query_word;
};

class NotQuery : public QueryBase {
	friend Query operator~(const Query&);
	NotQuery(const Query &q) :operand(q) {};
	QueryResult eval(const TextQuery&) const override;
	string rep() const override { return "~(" + operand.rep() + ")"; };
	Query operand;
};

inline 
QueryResult NotQuery::eval(const TextQuery &tq) const
{
	auto oper = operand.eval(tq);
	set<size_t> whole;
	for (size_t i = 0; i != oper.get_file()->size(); ++i)
		whole.insert(i);
	
	shared_ptr<set<size_t>> ret_lines(new set<size_t>);
	set_difference(whole.begin(), whole.end(), oper.begin(), oper.end(),
		inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(rep(), ret_lines, oper.get_file());
}


inline 
Query operator~(const Query &operand)
{
	return shared_ptr<QueryBase>(new NotQuery(operand));
}


class BinaryQuery : public QueryBase {
protected:
	BinaryQuery(const Query&l, const Query&r, const string&s):
		lhs(l), rhs(r), operator_symbol(s) {}
	string rep() const override { return "(" + lhs.rep() + " " +
		                                  operator_symbol + " " +
		                                  rhs.rep() + ")"; }
	Query lhs, rhs;
	string operator_symbol;
};

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &l, const Query &r) :
		BinaryQuery(l, r, "&") {};
	QueryResult eval(const TextQuery&) const override;
};

inline 
QueryResult AndQuery::eval(const TextQuery &tq) const
{
	set<size_t> ret;
	auto left = lhs.eval(tq), right = rhs.eval(tq);
	set_intersection(left.begin(), left.end(), right.begin(), right.end(),
		inserter(ret, ret.begin()));
	return QueryResult(rep(), make_shared<set<size_t>>(ret), left.get_file());
}

inline
Query operator&(const Query &lhs, const Query &rhs)
{
	return shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}


class OrQuery : public BinaryQuery {
	friend Query operator|(const Query&, const Query&);
	OrQuery(const Query &l, const Query &r) :
		BinaryQuery(l, r, "|") {};
	QueryResult eval(const TextQuery&) const override;
};

inline 
QueryResult OrQuery::eval(const TextQuery &tq) const
{
	auto left = lhs.eval(tq), right = rhs.eval(tq);
	shared_ptr<set<size_t>> ret_lines(new set<size_t>);
	set_union(left.begin(), left.end(), right.begin(), right.end(),
		inserter(*ret_lines, ret_lines->begin()));
	return QueryResult(rep(), ret_lines, left.get_file());
}


inline 
Query operator|(const Query &lhs, const Query &rhs)
{
	return shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

inline 
Query::Query(const string &s): p(new WordQuery(s)) {}


int main()
{
	ifstream input("storyDataFile");
	TextQuery tq(input);
	Query q1 = Query("Daddy");
	cout << q1 << endl;
	cout << q1.eval(tq) << endl;

	Query q5 = ~Query("Alice");
	cout << q5 << endl;
	cout << q5.eval(tq) << endl;

	Query q2 = Query("hair") | Query("Alice");
	cout << q2 << endl;
	cout << q2.eval(tq) << endl;

	Query q3 = Query("hair") & Query("Alice");
	cout << q3 << endl;
	cout << q3.eval(tq) << endl;

	Query q4 = Query("fiery") & Query("bird") | Query("wind");
	cout << q4 << endl;
	cout << q4.eval(tq) << endl;

	system("pause");
}