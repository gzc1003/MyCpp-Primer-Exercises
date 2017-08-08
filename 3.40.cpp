#include <cstring>
#include <iostream>
using std::cout; using std::endl;

int main()
{
    const char str1[] = "hello, ", str2[] = "world";
    char result[100];
    strcpy(result, str1);
    strcat(result, str2);
    cout << result << endl;
    return 0;
}