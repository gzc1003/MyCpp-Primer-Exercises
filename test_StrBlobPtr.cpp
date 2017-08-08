#include "StrBlob.h"
#include <cassert>
#include <string>
#include <iostream>

using std::string;
using std::cout; using std::endl;

int main()
{
	StrBlob sb{ "hello", "world", "guo", "zichun" };
	assert(sb[1] == string("world"));
	for (auto &s : sb)
		std::cout << s << " ";
	std::cout << std::endl;

	auto beg = sb.begin();
	cout << *beg << " length: " << beg->size() << endl;
	cout << beg[1] << " length: " << beg[1].size() << endl;

	const StrBlob sb2{ "hello", "world", "guo", "zichun" };
	assert(sb2[1] == string("world"));
}