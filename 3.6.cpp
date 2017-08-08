#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

//int main()
//{
//    string target{ "abcdefg" };
//    cout << target << '\n';
//    for (auto &c : target)
//        c = 'X';
//    cout << target << '\n';
//    return 0;
//}

int main()
{
    string target("abcdefg");
    cout << target << endl;

    decltype(target.size()) i = 0;
    while (i < target.size()) {
        target[i] = 'X';
        ++i;
    }
    cout << target << endl;

    for (string::size_type i = 0; i < target.size(); ++i)
        target[i] = 'Y';
    cout << target << endl;

    return 0;
}
