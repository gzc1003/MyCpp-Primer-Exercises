#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;
#include <fstream>
using std::ifstream;

// ascenders and descenders come from 
// http://boards.straightdope.com/sdmb/showthread.php?t=685735

int main()
{
    ifstream input("poem.txt");
    if (input) {
        string longest;
        for (string word; input >> word;) {
            if (word.find_first_of("bdfhiklt") == word.npos &&
                word.find_first_of("gjpqy") == word.npos && 
                word.size() > longest.size())
                longest = word;
        }
        cout << longest << endl;
    } else {
        std::cerr << "open fail" << endl;
        return -1;
    }

    return 0;
}
