#include <iostream>
using std::cout; using std::endl;

struct numbered {
	numbered() :mysn(id) { ++id; }
	numbered(const numbered &n) : mysn(id) { ++id; }
	int mysn;
private:
	static int id;
};

int numbered::id = 0;

void f(numbered s) { cout << s.mysn << endl; }

int main()
{
	numbered a, b = a, c = b;
	f(a); f(b); f(c);
}