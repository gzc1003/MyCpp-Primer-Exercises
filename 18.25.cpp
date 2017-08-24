#include <iostream>
using namespace std;

class Base1 {
public:
	virtual ~Base1() { cout << "~Base1()" << endl; }
};

class Base2 {
public:
	virtual ~Base2() { cout << "~Base2()" << endl; }
};

class D1 : public Base1 {
public:
	virtual ~D1() { cout << "~D1()" << endl; }
};


class D2 : public Base2 {
public:
	virtual ~D2() { cout << "~D2()" << endl; }
};


class MI : public D1, public D2 {
public:
	virtual ~MI() { cout << "~MI()" << endl; }
};


int main()
{
	Base2 *pb2 = new MI;
	delete pb2;
	return 0;
}