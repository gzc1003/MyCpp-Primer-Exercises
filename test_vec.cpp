#include <iostream>
#include "Vec.h"

int main()
{
	Vec<int> vec{ 0,1,2,3,4 };
	std::cout << vec.capacity() << std::endl;
	vec.resize(10);
	std::cout << vec.capacity() << std::endl;
	for (auto &i : vec)
		std::cout << i << " ";
	std::cout << std::endl;

	vec.reserve(20);
	std::cout << vec.capacity() << std::endl;
	for (auto &i : vec)
		std::cout << i << " ";
	std::cout << std::endl;
}