#pragma once

#include <memory>
#include <string>
#include <vector>
#include <initializer_list>
#include <stdexcept>

class StrBlobPtr;

class StrBlob {
	friend class StrBlobPtr;
public:
	using size_type = std::vector<std::string>::size_type;
	
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

	std::string& operator[](size_type i);
	const std::string& operator[](size_type i) const;

	StrBlobPtr begin();
	StrBlobPtr end();

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, std::string message) const;
};

inline
StrBlob::StrBlob() :
	data(std::make_shared<std::vector<std::string>>()) {}

inline
StrBlob::StrBlob(std::initializer_list<std::string> li) :
	data(std::make_shared<std::vector<std::string>>(li)) {}

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


class StrBlobPtr {
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	//friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &s, size_t c = 0) : wptr(s.data), curr(c) {}

	std::string& operator*() const;
	std::string* operator->() const;

	StrBlobPtr& operator++();
	StrBlobPtr operator++(int);

	StrBlobPtr& operator--();
	StrBlobPtr operator--(int);

	std::string& operator[](size_t i);
	const std::string& operator[](size_t i) const;

	StrBlobPtr& operator+=(size_t i);
	StrBlobPtr& operator-=(size_t i);

	StrBlobPtr operator+(size_t i) const;
	StrBlobPtr operator-(size_t i) const;

private:
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
	std::shared_ptr<std::vector<std::string>>
		check(size_t n, const std::string &msg) const;
};


bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
