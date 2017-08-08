#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    vector<string> text;
    
    for (string word; cin >> word; text.push_back(word));

    for (auto &word : text)
        for (auto &c : word)
            c = toupper(c);
    
    for (auto &word : text)
        cout << word << endl;

    return 0;
}