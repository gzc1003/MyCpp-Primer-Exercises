#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

// while

//int main()
//{
//    string tmp;
//    vector<string> text;
//    while (cin >> tmp)
//       text.push_back(tmp);
//    for (auto word : text)
//        cout << word << endl;
//    return 0;
//}

// for
int main()
{
    vector<string> text;
    for (string buffer; cin >> buffer; text.push_back(buffer))
        ;
    return 0;
}