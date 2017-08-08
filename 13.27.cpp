#include <string>
class HasPtr {
public:
	HasPtr(const std::string &s = std::string()) :
		ps(new std::string(s)), i(0), reference_count(new size_t(1)){}
	HasPtr(const HasPtr& hptr):
		ps(hptr.ps), i(hptr.i), reference_count(hptr.reference_count) 
	{
		++*reference_count;
	}
	HasPtr &operator=(const HasPtr&);
	~HasPtr();
private:
	std::string *ps;
	int i;
	size_t *reference_count;
};

inline
HasPtr::~HasPtr()
{
	if (--*reference_count == 0) {
		delete ps;
		delete reference_count;
	}
}

inline
HasPtr& HasPtr::operator=(const HasPtr& rhs) 
{
	++*rhs.reference_count;
	if (--*reference_count == 0) {
		delete ps;
		delete reference_count;
	}
	ps = rhs.ps;
	i = rhs.i;
	reference_count = rhs.reference_count;
	return *this;
}