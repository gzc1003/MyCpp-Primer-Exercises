#include <iostream>
#include "SalesData.h"

template <typename T>
int compare(const T &lhs, const T &rhs)
{
	if (lhs < rhs) return -1;
	else if (rhs < lhs) return 1;
	else return 0;
}

int main()
{
	SalesData s1, s2;
	std::cout << compare(s1, s2);
}