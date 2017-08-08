#include <string>
#include <iostream>
#include <vector>

class ReadString {
public:
	std::string operator()(std::istream &is)
	{
		std::string s;
		std::getline(is, s);
		return s;
	}
};


class AnotherReadString {
public:
	AnotherReadString(std::istream &in):is(in) {};
	std::string operator()() const 
	{
		std::string s;
		std::getline(is, s);
		return is ? s : std::string();
	}
private:
	std::istream &is;
};



int main()
{
	std::vector<std::string> vec;
	//ReadString read;
	//std::string s;
	//for (std::string s; s=read(std::cin),s.size()!=0; )
	//	vec.push_back(s);
	//for (auto s : vec)
	//	std::cout << s << std::endl;
	AnotherReadString read(std::cin);
	std::string s;
	for (std::string s; s = read(), !s.empty(); )
		vec.push_back(s);
	for (const auto &s: vec)
		std::cout << s << std::endl;
}