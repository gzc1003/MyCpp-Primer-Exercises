#include <vector>
#include <iostream>
#include <algorithm>

class isNum {
public:
	isNum(int n): num(n) {}
	bool operator()(int value) {return value == num; }
private:
	int num;
};

int main()
{
	isNum is_num(3);
	std::vector<int> vec{ 2,3,3,4,5,3,2 };
	std::replace_if(vec.begin(), vec.end(), is_num, 42);
	for (auto i : vec)
		std::cout << i << " ";
	std::cout << std::endl;
}