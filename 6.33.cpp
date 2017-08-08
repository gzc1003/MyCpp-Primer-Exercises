#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;


void output(vector<int>::const_iterator beg, vector<int>::const_iterator end)
{
    if (beg != end) {
        cout << *beg++ << " ";
        output(beg, end);
    }
}

int main()
{
    vector<int> v{ 1,2,3,4 };
    output(v.begin(), v.end());
}