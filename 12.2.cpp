
#include "12.2.h"
#include <iostream>

int main()
{
	StrBlob b1;
	{
		StrBlob b2 = { "hello", "world", "by", "guo" };
		b1 = b2;
		b2.push_back("zichun");
	}
	std::cout << b1.size() << std::endl;

	auto size = b1.size();
	b1.back() = "GUO";
	for (decltype(b1.size()) i = 0; i != size; ++i) {
		std::cout << b1.back() << " ";
		b1.pop_back();
	}
	std::cout << std::endl;

	return 0;
}