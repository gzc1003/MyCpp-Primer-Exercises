#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <iterator>

using namespace std;

int main()
{
    map<string, size_t> words_count;
    set<string> exclude = { "the", "and", "a", "an", "but",
                           "The", "And", "A", "An", "But" };
    string word;
    while (cin >> word) {
        if (exclude.find(word) == exclude.end()) {
            string new_word;
            copy_if(word.cbegin(), word.cend(), back_inserter(new_word), 
                [](const char c) {return isalpha(c); });
            for_each(new_word.begin(), new_word.end(),
                [](char &c) {c=tolower(c); });
            ++words_count[new_word];
        }
    }
    for (auto p : words_count)
        cout << p.first << " occurs " << p.second << " " <<
        ((p.second > 1) ? "times" : "time") << endl;
}