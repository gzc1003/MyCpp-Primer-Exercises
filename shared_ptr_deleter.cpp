#include <memory>
#include <iostream>

class DebugDelete {
public:
	DebugDelete(std::ostream &o = std::cerr) : os(o) {}
	template <typename T> void operator()(T *p) const
	{
		os << "delete unique_ptr" << std::endl;
		delete p;
	}
private:
	std::ostream &os;
};

int main()
{
	std::shared_ptr<int> sptr, sptr1(new int(42), DebugDelete());
}