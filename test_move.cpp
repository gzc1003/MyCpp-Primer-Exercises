#include <utility>
#include <iostream>

struct X {
	X() = default;
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	//X(X&&) { std::cout << "X(X&&)" << std::endl; }
	//X(const X&) = delete;
	int i;
};

struct hasX {
	X mem;
	hasX(const hasX &) = delete;
	hasX(hasX &&) = default;
	hasX() = default;
};

int main()
{
	//X x1, x2 = std::move(x1);
	hasX hx, hx2 = std::move(hx);
}