#include <iostream>
using std::cout;

template <typename T, const unsigned N>
T *begin(T(&arr)[N])
{
	return arr;
}

template <typename T, const unsigned N>
T *end(T(&arr)[N])
{
	return arr+N;
}


int main()
{
	int a[] = { 1,2,3,4,5 };
	for (auto beg = ::begin(a); beg != ::end(a); ++beg)
		cout << *beg << " ";
}