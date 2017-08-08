#include <vector>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    vector<string> text = {"paragraph1", "section1", "section2",
                           "",                                  
                           "paragraph2"};

    for (auto line : text)
        cout << line << endl;
    cout << endl;
    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
        for (auto it_line = it->begin(); it_line != it->end(); ++it_line)
            *it_line = toupper(*it_line);
        cout << *it << endl;
    }
    return 0;
}