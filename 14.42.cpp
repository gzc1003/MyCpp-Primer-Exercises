#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>

using namespace std::placeholders;

int main()
{
	
	std::vector<std::string> vecs = { "pooh","hello", "pa"};

	std::vector<int> vec = {1,11,111,1111,1111};
	auto res = std::count_if(vec.begin(), vec.end(),
		std::bind(std::greater<int>(), _1, 1024));
	std::cout << res << std::endl;


	auto iter=std::find_if(vecs.begin(), vecs.end(),
		std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
	if (iter != vecs.end())
		std::cout << *iter << std::endl;

	std::transform(vec.begin(), vec.end(), vec.begin(),
		std::bind(std::multiplies<int>(), _1, 2));
	for (auto i : vec)
		std::cout << i << " ";
	std::cout << std::endl;
}