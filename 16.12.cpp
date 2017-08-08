#include <initializer_list>
#include <vector>
#include <memory>
#include <string>
#include <exception>
#include <cassert>
#include <iostream>

template <typename T> class BlobPtr;

template <typename T> class Blob {
	friend class BlobPtr<T>;
public:
	typedef T value_type;
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	Blob(std::initializer_list<T>);
	template <typename It> Blob(It beg, It last) :
		data(std::make_shared<std::vector<T>>(beg, last)) {}

	BlobPtr<T> begin();
	BlobPtr<T> end();

	size_type size() const { return data->size(); } 
	void push_back(const T &t) { data->push_back(t); }
	void push_back(T &&t) { data->push_back(std::move(t)); }
	void pop_back();
	T& front();
	T& back();
	T& operator[](size_type);
private:
	std::shared_ptr<std::vector<T>> data;
	void check(size_type, const std::string&) const;
};

template <typename T> bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);
template <typename T> bool operator!=(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T> class BlobPtr {
	friend bool operator==<T>(const BlobPtr&, const BlobPtr&);
	friend bool operator!=<T>(const BlobPtr&, const BlobPtr&);
public:
	BlobPtr(): curr(0) {}
	BlobPtr(Blob<T> &a, std::size_t i=0) : wptr(a.data), curr(i) {}

	T& operator*() const;
	
	BlobPtr& operator++();
	BlobPtr operator++(int);


private:
	std::weak_ptr<std::vector<T>> wptr;
	std::size_t curr;
	std::shared_ptr<std::vector<T>> check(size_t, const std::string&) const;
};


// Blob
template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
	data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
void Blob<T>::check(size_type n, const std::string &msg) const
{
	if (n >= data->size())
		throw std::out_of_range(msg);
}

template <typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob<T>");
	data->pop_back();
}

template <typename T>
T& Blob<T>::front()
{
	check(0, "front on empty Blob<T>");
	return data->front();
}

template <typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob<T>");
	return data->back();
}

template <typename T>
BlobPtr<T> Blob<T>::begin()
{
	return BlobPtr<T>(*this);
}

template <typename T>
BlobPtr<T> Blob<T>::end()
{
	return BlobPtr<T>(*this, size());
}


template <typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript past the end");
	return (*data)[i];
}



// BlobPtr
template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
	return !(lhs == rhs);
}



template <typename T>
std::shared_ptr<std::vector<T>> 
BlobPtr<T>::check(size_t n, const std::string &msg) const
{
	auto sptr = wptr.lock();
	if (!sptr)
		throw std::runtime_error("unbound BlobPtr<T>");
	if (n >= sptr->size())
		throw std::out_of_range(msg);
	return sptr;
}

template <typename T>
T& BlobPtr<T>::operator*() const
{
	auto sptr = check(curr, "dereference past end");
	return (*sptr)[curr];
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{	
	check(curr, "increment past end");
	++curr;
	return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	auto ret = *this;
	++*this;
	return ret;
}




using std::string;
using std::cout; using std::endl;

int main()
{
	using StrBlob = Blob<string>;
	StrBlob sb{ "hello", "world", "guo", "zichun" };
	assert(sb[1] == string("world"));
	for (auto &s : sb)
		std::cout << s << " ";
	std::cout << std::endl;
}