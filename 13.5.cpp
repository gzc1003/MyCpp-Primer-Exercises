#include <string>
class HasPtr {
public:
	HasPtr(const std::string &s=std::string()):
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& hptr):
		ps(new std::string(*hptr.ps)),i(hptr.i) {}
	HasPtr &operator=(const HasPtr& hptr)
	{
		auto tmp_ptr = new std::string(*hptr.ps);
		delete ps;     
		ps = tmp_ptr;
		i = hptr.i;
		return *this;
	}

	~HasPtr() { delete ps; }
private:
	std::string *ps;
	int i;
};
