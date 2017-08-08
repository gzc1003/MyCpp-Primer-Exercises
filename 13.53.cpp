#include "HasStrOne.h"
#include "HasStr.h"

void testHasStrOne()
{
	HasPtrOne hp2("hello"), hp;
	hp = hp2;
	//hp = std::move(hp2);
}

void testHasStr()
{
	HasPtr hp2("hello"), hp;
	hp = hp2;
	//hp = std::move(hp2);
}


int main()
{
	for (auto i = 0; i != 10000; ++i) {
		testHasStr();
		testHasStrOne();
	}
	return 0;
}