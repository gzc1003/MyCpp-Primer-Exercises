#include "elimDups.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector; using std::string;

void biggies(vector<string> &rvec, string::size_type sz)
{
    elimDups(rvec);
    std::stable_sort(rvec.begin(), rvec.end(),
        [](const string &s1, const string &s2)
    {return s1.size() < s2.size(); });

    auto start = std::find_if(rvec.begin(), rvec.end(),
        [sz](const string &s)
    {return s.size() >= sz; });

    auto count = rvec.end() - start;
    std::cout << count << " longer than " << sz << " or longer" << std::endl;
    
    std::for_each(start, rvec.end(),
        [](const string &s) {std::cout << s << " "; });
    std::cout << std::endl;
}

int main()
{
    biggies(vector<string>{"aaa", "bb", "cccc", "ddd", "eeeee", "f"}, 3);
    return 0;
}