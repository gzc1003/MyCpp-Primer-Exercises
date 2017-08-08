#include <memory> 
#include <utility>
#include <iostream>

class String {
public:
	String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char*);
	~String() { free(); }

	size_t size() { return first_free - elements; }
	void push_back(char);

	char *begin() const { return elements; }
	char *end() const { return first_free; }

private:
	char *elements;
	char *first_free;
	char *cap;
	static std::allocator<char> alloc;

	void reallocate();
	void free();
	void chk_n_alloc() { if (first_free == cap) reallocate(); }
};

std::allocator<char> String::alloc;

String::String(const char *c) :
	elements(nullptr), first_free(nullptr), cap(nullptr)
{
	while (*c)
		push_back(*c++);
}

void String::push_back(char c)
{
	chk_n_alloc();
	alloc.construct(first_free++, c);
}

void String::free()
{
	if (elements) {
		for (auto q = first_free; q != elements;)
			alloc.destroy(--q);
		alloc.deallocate(elements, cap - elements);
	}
}

void String::reallocate()
{
	size_t new_size = size() > 0 ? 2 * size() : 1;
	auto data = alloc.allocate(new_size);
	auto p = data;
	for (auto beg = elements; beg != first_free; ++beg)
		alloc.construct(p++, std::move(*beg));
	free();
	elements = data;
	first_free = p;
	cap = data + new_size;
}


std::ostream& operator<<(std::ostream &out, const String &s)
{
	for (auto &c : s) out << c;
	return out;
}


int main()
{
	String s("hello world!");
	std::cout <<s<< std::endl;
	std::system("pause");
	return 0;
}