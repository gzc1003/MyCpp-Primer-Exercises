#include <string>

struct Employee {
	Employee() : id(unique) { ++unique; }
	Employee(const std::string name) :
		name(name), id(unique){++unique;}

	Employee(const Employee&) = delete;
	Employee &operator=(const Employee&) = delete;

	std::string name;
	int id;
private:
	static int unique;
};

int Employee::unique = 0;