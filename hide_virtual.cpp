#include <iostream> 


class Base {
public:
	virtual void fcn() {}
	virtual void fcn2() 
	{
		std::cout << "virtual void Base::fcn2()" << std::endl;
	}
	int base_mem = 1;
};

class D1 : public Base {
public:
	void fcn(int) {}
	int d1_mem = 2;
};

class D2 : public D1 {
public:
	void fcn2() override 
	{
		std::cout << "virtual void D2::fcn2()" << std::endl;
	}
	int d2_mem = 3;
};

int main()
{

	D1 objd1;
	D2 objd2, *objd2p = &objd2;
	D1 *d1p = &objd2;
	//pd->fcn();
	d1p->fcn2();

	auto i = objd2p->d2_mem;
	auto j = objd2p->d1_mem;
	auto k = objd2p->base_mem;

}