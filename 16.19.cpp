#include <iostream>
#include <vector>

template <typename C>
void print(C &c)
{
	using size_type = typename C::size_type;
	for (size_type i = 0; i != c.size(); ++i)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	for (auto iter = c.begin(); iter != c.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> vec{ 0,1,2,3,4 };
	print(vec);
}