#pragma once
#include <cstddef>
#include <functional>

template <typename T> class SharedPtr {
public:
	typedef std::function<void(T*)> Deleter;
	SharedPtr():
		ptr(new T()),count(new std::size_t(1)) {}
	SharedPtr(const SharedPtr &sp) :
		ptr(sp.ptr), del(sp.del), count(sp.count) {
		++*count;
	}
	explicit SharedPtr(T *p) :
		ptr(p), count(new std::size_t(1)) {}
	SharedPtr(T *p, Deleter d) :
		ptr(p), del(d), count(new std::size_t(1)) {}
	~SharedPtr() { free(); }

	SharedPtr& operator=(const SharedPtr &rhs)
	{
		++*rhs.count;
		free()
		ptr = rhs.ptr;
		del = rhs.del;
		count = rhs.count;
		return *this;
	}

	T* operator->() const { return ptr; }
private:
	T* ptr;
	std::function<void(T*)> del;
	std::size_t *count;

	void free() 
	{ 
		if (--*count == 0) {
			del ? del(ptr) : delete ptr;
			delete count;
		}
	}
};



class DefaultDeleter {
public:
	template <typename T> 
	void operator()(T *p) const { delete p; }
};


template <typename T, typename Deleter = DefaultDeleter>
class UniquePtr {
public:
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;

	UniquePtr() = default;
	UniquePtr(Deleter d): del(d) {}
	explicit UniquePtr(T *p, Deleter d = Deleter()):
		ptr(p), del(d) {}
	~UniquePtr() { del(ptr); }
private:
	T *ptr = nullptr;
	Deleter del = Deleter();
};


