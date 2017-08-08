#include "elimDups.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using std::vector; using std::string;

void biggies(vector<string> words, string::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(),
        [](const string &s1, const string &s2)
    {return s1.size() < s2.size(); });
    //auto pivot = std::partition(words.begin(), words.end(),
    //    [sz](const string &s) {return s.size() >= sz; });
    auto pivot = std::stable_partition(words.begin(), words.end(),
        [sz](const string &s) {return s.size() >= sz; });
    auto count = pivot - words.begin();
    std::cout << count << " longer than " << sz 
        << " or longer" << std::endl;
    std::for_each(words.begin(), pivot, 
        [](const string &s) {std::cout << s << " "; });
    std::cout << std::endl;
}

int main()
{
    biggies(vector<string>{"aaa", "bb", "cccc", "ddd", "eeeee", "f"}, 3);
    return 0;
}