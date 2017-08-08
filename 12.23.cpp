#include <iostream>
#include <memory>
#include <cstring>
#include <memory>
#include <string>

using std::string;
using std::unique_ptr;

char *cat(const char *s1, const char *s2)
{
	char *s = new char[strlen(s1) + strlen(s2) + 1];
	strcat(s, s1);
	strcat(s, s2);
	return s;
}


unique_ptr<char[]> cat_s(const string &s1, const string &s2)
{
	string s = s1 + s2;
	unique_ptr<char[]> u(new char[s1.size() + s2.size() + 1]);
	size_t i;
	for (i = 0; i != s.size(); ++i)
		u[i] = s[i];
	u[i] = '\0';
	return u;
}


int main()
{
	auto p = cat("guo", "zichun");
	std::cout << p << std::endl;
	delete[] p;

	std::cout << cat_s("guo", "zichun").get() << std::endl;
	return 0;
}