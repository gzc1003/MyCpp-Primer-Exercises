#include <cstring>
#include <string>
using std::string;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    string str1("hello"), str2("hiho");
    cout << (str1 < str2) << endl;

    const char cstr1[] = "hello", cstr2[] = "hiho";
    cout << (strcmp(cstr1, cstr2)<0) << endl;

    return 0;
}
