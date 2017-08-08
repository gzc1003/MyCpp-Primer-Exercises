#include <iostream>
using std::cout; using std::endl;

int main()
{
    cout << "int size: "<< sizeof(int) << endl;
    cout << "long size: "<<sizeof(long) << endl;
    cout << "char size: "<<sizeof(char) << endl;
    cout << "pointer size: "<< sizeof(int *) << endl;

    cout << "int64_t size: "<<sizeof(int64_t) << endl;

    return 0;
}