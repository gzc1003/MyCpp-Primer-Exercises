#include <string>
using std::string;
#include <deque>
using std::deque;
#include <iostream>
using std::cout; using std::cin;


int main()
{
    deque<string> dq;
    string s;
    while (cin >> s)
        dq.push_back(s);
    for (auto iter=dq.begin(); iter != dq.end(); ++iter)
        cout << *iter << " ";
    return 0;
}