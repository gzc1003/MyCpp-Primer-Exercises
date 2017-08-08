#include <iostream>
using std::cout; using std::endl; using std::cin;

unsigned count_call()
{
    static unsigned count = 0;
    return count++;
}

int cal_sum(int n)
{
    static int whole_sum = 0;
    whole_sum += n;
    return whole_sum;
}

int main()
{
    for (int i = 0; i != 10; ++i)
        cout << cal_sum(i) << endl;
    return 0;
}