#include <list>
using std::list;
#include <vector>
using std::vector;
#include <string>
using std::string;

int main()
{
    list<char *> l1 = { "hello", "world" };
    vector<string> v1;
    v1.assign(l1.cbegin(), l1.cend());
}
