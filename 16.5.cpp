#include <iostream>

template <typename T, const unsigned N>
void print(const T(&arr)[N])
{
	for (const auto &i : arr)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main()
{
	int a[] = { 1,2,3,42 };
	print(a);
}