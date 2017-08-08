#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>
#include <utility>
#include <iterator>
#include <initializer_list>
#include <algorithm>

class StrVec {
public:
	StrVec() :
		elements(nullptr), first_free(nullptr), cap(nullptr) {}
	StrVec(const StrVec&);
	StrVec(StrVec&&) noexcept;

	StrVec(std::initializer_list<std::string>);

	StrVec& operator=(const StrVec&);
	StrVec& operator=(StrVec&&) noexcept;

	~StrVec();

	void push_back(const std::string &);
	std::string* begin() const { return elements; }
	std::string* end() const { return first_free; }

	size_t size() const { return first_free - elements; }
	void resize(size_t n, const std::string &s = std::string());

	size_t capacity() const { return cap - elements; }
	void reserve(size_t n) { if (n > capacity()) reallocate_n(n); }

private:
	std::string *elements;
	std::string *first_free;
	std::string *cap;

	static std::allocator<std::string> alloc;
	void free();
	void reallocate();
	void reallocate_n(size_t);
	auto alloc_n_copy(const std::string*, const std::string*)
		->std::pair<std::string*, std::string*>;
	auto alloc_n_move(const std::string*, const std::string*)
		->std::pair<std::string*, std::string*>;
	void chk_n_alloc() { if (first_free == cap) reallocate(); }
};

std::allocator<std::string> StrVec::alloc;

std::pair<std::string*, std::string*>
StrVec::alloc_n_copy(const std::string *beg, const std::string *last)
{
	size_t size = last - beg;
	auto p = alloc.allocate(size);
	auto q = std::uninitialized_copy(beg, last, p);
	return{ p, q };
}

std::pair<std::string*, std::string*>
StrVec::alloc_n_move(const std::string *beg, const std::string *last)
{
	size_t size = last - beg;
	auto p = alloc.allocate(size);
	auto q = std::uninitialized_copy(std::make_move_iterator(beg),
		std::make_move_iterator(last), p);
	return{ p, q };
}



void StrVec::free()
{
	//if (elements) {
	//	for (auto q = first_free; q != elements; )
	//		alloc.destroy(--q);
	//	alloc.deallocate(elements, capacity());
	//}

	//use for_each
	if (elements) {
		std::for_each(elements, first_free,
			[](std::string &s) {alloc.destroy(&s); });
		alloc.deallocate(elements, capacity());
	}
}

//use move iterator
void StrVec::reallocate()
{
	size_t newcapcity = size() > 0 ? 2 * size() : 1;
	reallocate_n(newcapcity);
}

void StrVec::reallocate_n(size_t n)
{
	auto data = alloc.allocate(n);
	auto q = std::uninitialized_copy(std::make_move_iterator(elements),
		std::make_move_iterator(first_free), data);
	free();
	elements = data;
	first_free = q;
	cap = elements + n;
}

StrVec::StrVec(const StrVec &sv)
{
	auto p = alloc_n_copy(sv.begin(), sv.end());
	elements = p.first;
	cap = first_free = p.second;
}

StrVec::StrVec(StrVec &&s) noexcept :
elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	s.elements = s.first_free = s.cap = nullptr;
}

StrVec::StrVec(std::initializer_list<std::string> lst)
{
	auto p = alloc_n_move(lst.begin(), lst.end());
	elements = p.first;
	cap = first_free = p.second;
}

StrVec& StrVec::operator=(const StrVec &rhs)
{
	auto p = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = p.first;
	cap = first_free = p.second;
	return *this;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept
{
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	return *this;
}


StrVec::~StrVec()
{
	free();
}

void StrVec::push_back(const std::string &s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);
}

void StrVec::resize(size_t n, const std::string &s)
{
	if (n > size()) {
		for (size_t i = size(); i != n; ++i)
			push_back(s);
	} else if (n < size()) {
		for (auto q = first_free; q != elements + n; )
			alloc.destroy(--q);
		first_free = elements + n;
	}
}

#endif // !STRVEC_H
