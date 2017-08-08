#include <string>
using std::string;

string(&func(int i))[10];

using arrT = string[10];
arrT &func(int i);

auto func(int i)->string(&)[10];

string arrs[10];
decltype(arrs) &func(int i);
