#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;

struct X {
	X() { cout << "X()" << endl; }
	X(int) { cout << "X(int)" << endl; }
	X(const X&) { cout << "X(const X&)" << endl; }

	X &operator=(const X&)
	{
		cout << "X &operator=(const X&)" << endl;
		return *this;
	}

	~X() { cout << "~X()" << endl; }

	int data;
};

void pass_by_value(X) { cout << "in function pass_by_value" << endl; }

void pass_by_reference(X &) {  }


int main()
{
	{X x1;
	X x2 = x1;
	x2 = x1;
	X x3 = 1;
	vector<X> vec1(1), vec2(vec1);
	auto p1 = new X, p2 = new X(2);

	pass_by_reference(x1);

	cout << "pass_by_value: ";
	pass_by_value(x1);
	}
	system("pause");
	return 0;
}