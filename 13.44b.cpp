#include <memory> 
#include <utility>
#include <iostream>
#include <cctype>



class String {
public:
	String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
	String(const char*);

	String(const String&);
	String(String&&) noexcept;

	String& operator=(const String&);
	String& operator=(String &&) noexcept;


	~String() { free(); }

	size_t size() { return first_free - elements; }
	void push_back(char);
	std::ostream& print(std::ostream &out)
	{
		for (auto &c : *this) out << c;
		return out;
	}

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
	std::pair<char*, char*>
		String::alloc_n_copy(const char*, const char*);
};

std::allocator<char> String::alloc;

String::String(const String &s)
{
	std::cout << "call String(const String &s)" << std::endl;
	auto p =alloc_n_copy(s.elements, s.first_free);
	elements = p.first;
	first_free = cap = p.second;
}


String::String(String &&s) noexcept:
elements(s.elements), first_free(s.first_free), cap(s.cap)
{
	std::cout << "call String(String &&s)" << std::endl;
	std::cout << "move ";
	print(std::cout) << std::endl;
	s.elements = s.first_free = s.cap = nullptr;
}


String::String(const char *c)
{
	std::cout << "call String(const char *c)" << std::endl;
	size_t n = std::strlen(c);
	auto data = alloc.allocate(n), p = data;
	for (size_t i = 0; i != n; ++i)
		alloc.construct(p++, std::move(c[i]));
	elements = data;
	first_free = cap = p;
}

String& String::operator=(const String &s)
{
	auto p = alloc_n_copy(s.elements, s.first_free);
	free();
	elements = p.first;
	first_free = cap = p.second;
	return *this;
}


String& String::operator=(String &&s) noexcept
{
	if (this != &s) {
		free();
		elements = s.elements;
		first_free = s.first_free;
		cap = s.cap;
		s.elements = s.first_free = s.cap = nullptr;
	}
	return *this;
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


std::pair<char*, char*>
String::alloc_n_copy(const char *b, const char *e)
{
	auto data = alloc.allocate(e-b);
	return{ data, std::uninitialized_copy(b, e, data) };
}



#include <vector>
int main()
{
	
	using std::cout; using std::endl;
	using std::vector;

	cout << "String s(\"laji...\")" << endl;
	String s("laji...");
	s.print(std::cout) << std::endl;
	cout << endl;

	vector<String> vec;
	cout << "vec.capacity "<< vec.capacity() << endl;
	cout << endl;

	cout << "vec.push_back(\"hello\")" << endl;
	vec.push_back("hello");
	cout << "vec.capacity " << vec.capacity() << endl;
	cout << endl;

	cout << "vec.push_back(\"world\");" << endl;
	vec.push_back("world");
	cout << "vec.capacity " << vec.capacity() << endl;
	cout << endl;

	std::system("pause");
	
	return 0;
}