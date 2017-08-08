#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector; using std::string;
using std::cout; using std::endl;

void more_than(const vector<string> &words, string::size_type sz)
{
    auto count = std::count_if(words.begin(), words.end(),
        [sz](const string &s) {return s.size() > sz; });
    std::cout << count << std::endl;
}

int main()
{
    more_than(vector<string>{"aaa", "bb", "cccc", "ddd", "eeeee", "f"}, 6);

    int i = 10;
    auto f = [&i]()->bool {i ? --i : i; return i == 0; };
    for (int n=1; n != 13; ++n)
        cout << n << ".\t" << std::boolalpha << f() << std::noboolalpha 
        << " i = " << i <<endl;
    return 0;
}