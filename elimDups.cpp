#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::cout; using std::endl; using std::cin;

void elimDups(vector<string> &words)
{
    std::sort(words.begin(), words.end());
    //for (auto s : words) cout << s << " ";
    //cout << endl;
    auto end_unique = std::unique(words.begin(), words.end());
    //for (auto s : words) cout << s << " ";
    //cout << endl;
    words.erase(end_unique, words.end());
    //for (auto s : words) cout << s << " ";
    //cout << endl;
}