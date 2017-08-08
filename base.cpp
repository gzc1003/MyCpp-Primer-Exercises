#include <cstdlib>
#include <iostream>

class Base {
public:
	virtual void foo() const { std::cout << "Base::foo()" << std::endl; }

};

class Derived : public Base{
public:
	void foo() const override { std::cout << "Derived::foo()" << std::endl; }
};

void print(const Base &b)
{
	b.foo();
}

int main()
{
	Base base;
	Derived derived;

	print(derived);
	
	base.foo();
	derived.foo();

	std::system("pause");
}