#include <iostream>

struct PubDerv;

class Base {
public:
	Base &operator=(const Base&)
	{
		std::cout << "Base& operator=(const Base&)";
		return *this;
	}
	Base &operator=(const PubDerv&)
	{
		std::cout << "Base &operator=(const PubDerv&)";
		return *this;
	}
	int pub_mem;
protected:
	int prot_mem;
private:
	int priv_mem;
};

struct PubDerv :public Base {
	//int foo() { return priv_mem; }
	int foo2() { return prot_mem; }
	int foo3() { return pub_mem; }

	void memfcn(Base &b) { b = *this; }
};

struct PrivDerv : private Base {
	//using Base::pub_mem;
	//using Base::prot_mem;
	//int foo() { return priv_mem; }
	int foo2() { return prot_mem; }
	int foo3() { return pub_mem; }
};

struct ProtDerv : protected Base {
	//int foo() { return priv_mem; }
	int foo2() { return prot_mem; }
	int foo3() { return pub_mem; }
	//void foo4(Base& base) { base.prot_mem = 1; }
	void foo5(ProtDerv& prot_derv) { prot_derv.prot_mem = 1; }
};

class DerivedFromPublic : public PubDerv {
	//int foo() { return priv_mem; }
	int foo2() { return prot_mem; }
	int foo3() { return pub_mem; }
};

class DerivedFromPrivate : public PrivDerv {
	//int foo() { return priv_mem; }
	//int foo2() { return prot_mem; }
	//int foo3() { return pub_mem; }
};

class DerivedFromProtected : public ProtDerv {
	//int foo() { return priv_mem; }
	int foo2() { return prot_mem; }
	int foo3() { return pub_mem; }
};


int main()
{
	Base *p;
	PubDerv d1;
	PrivDerv d2;
	ProtDerv d3;
	DerivedFromPublic dd1;
	DerivedFromPrivate dd2;
	DerivedFromProtected dd3;

	p = &d1;
	//p = &d2;
	//p = &d3;
	//p = &dd1;
	//p = &dd2;
	//p = &dd3;

	d1.memfcn(*p);
}