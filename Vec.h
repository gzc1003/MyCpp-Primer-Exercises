#pragma once
#include <utility>
#include <memory>
#include <iterator>
#include <initializer_list>

template <typename T> class Vec {
public:
	Vec() = default;
	Vec(const Vec&);
	Vec(std::initializer_list<T>);
	//Vec(Vec &&);
	Vec& operator=(const Vec&);
	~Vec() { free(); }

	void push_back(const T&);
	T* begin() { return elements; } 
	const T* begin() const { return elements; }
	T* end() { return first_free; }
	const T* end() const { return first_free; }

	size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }

	void resize(size_t n, const T &t= T());
	void reserve(size_t);

private:
	T* elements = nullptr;
	T* first_free = nullptr;
	T* cap = nullptr;
	static std::allocator<T> alloc;

	void free();
	void reallocate();
	std::pair<T*, T*> alloc_n_copy(const T*, const T*);
	std::pair<T*, T*> alloc_n_move(const T*, const T*);
	void chk_n_alloc() { if (size() == capacity()) reallocate(); }
};

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
void Vec<T>::free()
{
	if (elements) {
		for (auto first = first_free; first != elements; )
			alloc.destroy(--first);
		alloc.deallocate(elements, capacity());
	}
}

template <typename T>
void Vec<T>::reallocate()
{
	size_t sz = size() ? size() * 2 : 1;
	auto p = alloc.allocate(sz), beg = p;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(p++, std::move(elements[i]));
	free();
	elements = beg;
	first_free = p;
	cap = beg + sz;
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T *b, const T *e)
{
	auto p = alloc.allocate(e - b);
	return{ p, std::uninitialized_copy(b, e, p) };
}

template <typename T>
std::pair<T*, T*> Vec<T>::alloc_n_move(const T *b, const T *e)
{
	auto p = alloc.allocate(e - b);
	return{ p, std::uninitialized_copy(std::make_move_iterator(b), 
		std::make_move_iterator(e), p) };
}

template <typename T>
void Vec<T>::push_back(const T &t)
{
	chk_n_alloc();
	alloc.construct(first_free++, t);
}

template <typename T>
void Vec<T>::resize(size_t n, const T &t)
{
	if (n < size()) {
		for (auto p = first_free; p != elements + n;)
			alloc.destroy(--p);
	} else if (n > size()) {
		if (n > capacity()) reserve(2 * n);
		std::uninitialized_fill(first_free, elements + n, t);
	}
	first_free = elements + n;
}

template <typename T>
void Vec<T>::reserve(size_t n)
{
	if (n > capacity()) {
		auto p = alloc.allocate(n);
		auto e = std::uninitialized_copy(std::make_move_iterator(begin()),
			std::make_move_iterator(end()), p);
		free();
		elements = p;
		first_free = e;
		cap = elements + n;
	}
}

template <typename T>
Vec<T>::Vec(const Vec &v)
{
	auto ptrs = alloc_n_copy(v.begin(), v.end());
	elements = ptrs.first;
	first_free = cap = ptrs.second;
}

template <typename T>
Vec<T>::Vec(std::initializer_list<T> il)
{
	auto ptrs = alloc_n_move(il.begin(), il.end());
	elements = ptrs.first;
	first_free = cap = ptrs.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec &rhs)
{
	auto ptrs = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = ptrs.first;
	first_free = cap = ptrs.second;
	return *this;
}

