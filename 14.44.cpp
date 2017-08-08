#include <functional>
#include <string>
#include <iostream>
#include <map>
#include <sstream>

int add(int lhs, int rhs) { return lhs + rhs; }

class Multiply {
public:
	int operator()(int lhs, int rhs) { return lhs*rhs;}
};

int divide(int lhs, int rhs) { return lhs / rhs; }

int main()
{
	std::map<std::string, std::function<int(int, int)>> binops;

	auto minus = [](int lhs, int rhs) {return lhs - rhs; };

	binops["+"] = add;
	binops["-"] = minus;
	binops["*"] = Multiply();
	binops["/"] = divide;
	binops["%"] = std::modulus<int>();

	std::string line;
	//while (std::getline(std::cin, line)) {
	//	std::istringstream iss(line);
	//	int lhs, rhs;
	//	std::string opt;
	//	iss >> lhs >> opt >> rhs;
	//	if (iss)
	//		std::cout << binops[opt](lhs, rhs) << std::endl;
	//	else
	//		std::cout << "input error!" << std::endl;
	//}
	while (std::cin) {
		int lhs, rhs;
		std::string opt;
		std::cin >> lhs >> opt >> rhs;
		if (std::cin)
			std::cout << binops[opt](lhs, rhs) << std::endl;
		else if (std::cin && !std::cin.eof())
			std::cout << "input error!" << std::endl;
	}
}