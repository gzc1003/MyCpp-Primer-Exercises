#include "elimDups.h"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::cout; using std::endl; using std::cin;

inline
bool isShorter(const string &s1, const string &s2)
{
    return  s1.size() < s2.size();
}


int main()
{
    string word;
    vector<string> vec;
    while (cin >> word)
        vec.push_back(word);
    for (auto &s : vec) cout << s << " ";
    cout << endl;
    elimDups(vec);

    std::stable_sort(vec.begin(), vec.end(), isShorter);
    for (auto &s : vec) cout << s << " ";
    cout << endl;

    return 0;
}