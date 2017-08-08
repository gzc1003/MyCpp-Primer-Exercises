#include <string>
using std::string;

int main()
{
    void *pv=0;
    const string *pcs=0;
    string *ps = 0;
    char *pc;

    pc = static_cast<char*>(pv);
    //pv = static_cast<void*>(const_cast<string*>(ps));

    pcs = const_cast<const string*>(ps);

    return 0;
}