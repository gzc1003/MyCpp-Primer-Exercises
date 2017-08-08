#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

void old_to_new(string &s, const string &oldVal, const string &newVal)
{
    for (auto curr = s.begin(); curr <= s.end()- oldVal.size(); ) {
        if (oldVal == string(curr, curr+oldVal.size())) {
            curr = s.erase(curr, curr + oldVal.size());
            curr = s.insert(curr, newVal.begin(), newVal.end()) + newVal.size();
        } else {
            ++curr;
        }
    }
}

int main()
{
    string s("thothru");

    old_to_new(s, "tho", "though");
    cout << s << endl;
    old_to_new(s, "thru", "through");
    cout << s << endl;

    return 0;
}