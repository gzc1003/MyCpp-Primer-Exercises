#include "StrBlob.h"
#include <stdexcept>
#include <string>

//StrBlobPtr
std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(size_t n, const std::string &msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("Unbound StrBlobPtr");
	if (n >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

std::string* StrBlobPtr::operator->() const
{
	return &*(*this);
}


StrBlobPtr& StrBlobPtr::operator++()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
	auto old = *this;
	++*this;
	return old;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	auto old = *this;
	--*this;
	return old;
}

std::string& StrBlobPtr::operator[](size_t i)
{
	auto p =check(i, "subscript past end");
	return (*p)[i];
}

const std::string& StrBlobPtr::operator[](size_t i) const
{
	return const_cast<StrBlobPtr*>(this)->operator[](i);
}

StrBlobPtr& StrBlobPtr::operator+=(size_t i)
{
	curr += i;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator-=(size_t i)
{
	curr -=i;
	return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t i) const
{
	auto ret = *this;
	ret += i;
	return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t i) const 
{
	auto ret = *this;
	ret-= i;
	return ret;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	return !(lhs == rhs);
}




//StrBlob
StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

std::string& StrBlob::operator[](size_type i)
{
	check(i, "subscript past end");
	return (*data)[i];
}

const std::string& StrBlob::operator[](size_type i) const 
{
	return const_cast<StrBlob*>(this)->operator[](i);
}