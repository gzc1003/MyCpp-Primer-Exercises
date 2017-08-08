#ifndef HASSTRONE_H
#define HASSTRONE_H

#include <string>
class HasPtrOne {
	friend void swap(HasPtrOne&, HasPtrOne&);
public:
	HasPtrOne(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0) {}
	HasPtrOne(const HasPtrOne& hptr) :
		ps(new std::string(*hptr.ps)), i(hptr.i) {}
	HasPtrOne(HasPtrOne &&h):ps(h.ps), i(h.i)
	{
		h.ps = nullptr;
	}
	HasPtrOne &operator=(HasPtrOne rhs)
	{
		swap(*this, rhs);
		return *this;
	}
	~HasPtrOne() { delete ps; }
private:
	std::string *ps;
	int i;
};

inline
void swap(HasPtrOne &lhs, HasPtrOne &rhs)
{
	using std::swap;
	swap(lhs.i, rhs.i);
	swap(lhs.ps, rhs.ps);
}
#endif


