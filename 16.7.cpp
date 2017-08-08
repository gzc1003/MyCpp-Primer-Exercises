#include <iostream>
using std::cout;

template <typename T, const unsigned N>
constexpr unsigned size(T(&arr)[N])
{
	return N;
}

int main()
{
	int a[] = { 1,2,3,4,5 };
	cout << size(a);
}