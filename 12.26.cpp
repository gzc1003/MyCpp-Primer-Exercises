#include <memory>
#include <string>
#include <iostream>

int main()
{
	int n = 10;
	std::allocator<std::string> alloc;
	auto const p = alloc.allocate(n);
	auto q = p;
	std::string s;
	while (std::cin >> s && q!=p+n) {
		alloc.construct(q++, s);
	}
	const size_t size = q - p;
	while (q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, n);
}