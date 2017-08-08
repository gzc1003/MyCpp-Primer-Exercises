#include <list>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::istream_iterator<std::string> in_iter(std::cin), eof;
    std::list<std::string> words(in_iter, eof);

    words.sort();
    for (auto s : words) std::cout << s << " ";
    std::cout << std::endl;
    words.unique();

    for (auto s : words) std::cout << s << " ";
    std::cout << std::endl;

    std::list<std::string> d;
    std::replace_copy(words.cbegin(), words.cend(),
        std::back_inserter(d), std::string("fox"), std::string("rabbit"));
    for (auto s : d) std::cout << s << " ";
    std::cout << std::endl;
}