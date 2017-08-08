#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std::placeholders;

bool f(int i)
{
	std::vector<int> vec{ 2,3,5,7 };
	for (auto j : vec)
		if (std::modulus<int>()(i, j))
			return false;
	return true;
}

bool f2(int i)
{
	std::vector<int> vec{ 2,3,5,7 };
	if (std::any_of(vec.begin(), vec.end(), std::bind(std::modulus<int>(), i, _1)))
		return false;
	return true;
}

int main()
{
	std::cout << std::boolalpha<<f(35) << std::endl;
	std::cout << std::boolalpha << f2(35) << std::endl;

	std::cout << std::boolalpha << f(210) << std::endl;
	std::cout << std::boolalpha << f2(210) << std::endl;
}