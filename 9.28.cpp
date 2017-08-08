#include <forward_list>
using std::forward_list;
#include <iostream>
using std::cout; using std::endl;
#include <string>
using std::string;

void find_then_insert(forward_list<string> &flst, const string &target,
    const string &inserted)
{
    auto curr = flst.begin(), prev = flst.before_begin();
    while (curr != flst.end()) {
        if (*curr == target) {
            flst.insert_after(curr, inserted);
            return;
        }
        prev = curr++;
    }
    flst.insert_after(prev, inserted);
}

int main()
{
    forward_list<string> flst = { "Marry", "has", "a", "little", "lamb" };
    for (auto s : flst)
        cout << s << " ";
    cout << endl;
    find_then_insert(flst, "little", "delicious");
    for (auto s : flst)
        cout << s << " ";
    cout << endl;
    find_then_insert(flst, "!", "!");
    for (auto s : flst)
        cout << s << " ";
    return 0;
}
