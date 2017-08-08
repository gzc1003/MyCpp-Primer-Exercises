#pragma once
#include <functional>

using std::function;

template <typename T> class SharedPtr {
public:
	using Deleter = function<void(T*)>;
	SharedPtr();
	SharedPtr(const SharedPtr&);
	SharedPtr& operator=(const SharedPtr&);
	explicit SharedPtr(T *raw_p) : ptr(raw_p), count(new unsigned(1)) {}
	SharedPtr(T *raw_p, Deleter d) : ptr(raw_p), del(d), count(new unsigned(1)) {}
	~SharedPtr() 
	{ 
		if (--*count == 0) { 
			del ? del(ptr) : delete ptr; 
			delete count; 
		} 
	}
private:
	T *ptr;
	function<void(T*)> del;
	unsigned *count;
};


class DefaultDeleter {
	template <typename T>
	void operator()(T *ptr) const
	{
		delete ptr;
	}
};


template <typename T, typename Deleter=DefaultDeleter> class UniquePtr {
public:
	UniquePtr();
	UniquePtr(const UniquePtr&) = delete;
	UniquePtr& operator=(const UniquePtr&) = delete;
	explicit UniquePtr(T*, Deleter d = DefaultDeleter());
	~UniquePtr() { del(ptr); }
private:
	T *ptr;
	Deleter del;
};