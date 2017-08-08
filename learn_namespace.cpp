#include <iostream>
using namespace std;

namespace outer {
	int a = 1;
	
	namespace inner {
		int c = 4;
	}

	int b = inner::c;
}

int main()
{
	cout << outer::b << endl;
}