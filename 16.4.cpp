#include <vector>
#include <list>
#include <iostream>

template <typename Iter, typename T>
Iter find(Iter beg, Iter last, const T &v)
{
	for (; beg != last; ++beg)
		if (*beg == v)
			return beg;
	return last;
}


int main()
{
	//std::vector<int> vec{ 1,2,3,4,5 };
	std::list<int> vec{ 1,2,3,4,5 };
	auto iter=::find(vec.begin(), vec.end(), 4);
	if (iter != vec.end())
		std::cout << *iter << std::endl;
	else
		std::cout << "not found" << std::endl;
}