#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <iostream>
#include "SharedPtr.h"

template <typename T> using shared_ptr = SharedPtr<T>;

class StrBlob {
public:
	using size_type = std::vector<std::string>::size_type;
	using iterator = std::vector<std::string>::iterator;
	StrBlob();
	StrBlob(std::initializer_list<std::string>);

	void push_back(const std::string s) { data->push_back(s); }
	void pop_back();

	std::string &back();
	std::string &back() const;

	std::string &front();
	std::string &front() const;

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	iterator begin() { return data->begin(); }
	iterator begin() const { return data->begin(); }
	iterator end() { return data->end(); }
	iterator end() const { return data->end(); }

private:
	shared_ptr<std::vector<std::string>> data;
	void check(size_type i, std::string message) const;
};

inline
StrBlob::StrBlob() :
	data(shared_ptr<std::vector<std::string>>()) {}

inline
StrBlob::StrBlob(std::initializer_list<std::string> li) :
	data(shared_ptr<std::vector<std::string>>(new std::vector<std::string>(li))) {}

inline
void StrBlob::check(size_type i, std::string message) const
{
	if (i >= size())
		throw std::out_of_range(message);
}

inline
void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

inline
std::string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

inline
std::string &StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

inline
std::string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

inline
std::string &StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}


using std::string;
using std::cout; using std::endl;


void d(int *)
{
	cout << "void d(int *p)" << endl;
}


int main()
{
	StrBlob sb{ "hello", "world", "guo", "zichun" };
	for (auto &s : sb)
		std::cout << s << " ";
	std::cout << std::endl;

	UniquePtr<int, decltype(d)*> up(d);
}