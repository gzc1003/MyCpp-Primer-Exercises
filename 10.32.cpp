#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <iostream>
#include "Sales_item.h"

bool compareisbn(const Sales_item &a, const Sales_item &b)
{
    return a.isbn() < b.isbn();
}


int main()
{
    std::ifstream input_file("book_sales");
    std::istream_iterator<Sales_item> in_iter(input_file), eof;
    std::vector<Sales_item> words(in_iter, eof);

    std::sort(words.begin(), words.end(), compareisbn);
    auto total = words.begin(), current = total+1;
    while (current != words.end()) {
        if ((std::find_if(current, words.end(), [total](Sales_item &s)
        {return s.isbn() == total->isbn(); })) != words.end()) {
            ++current;
        } else {
            std::cout << std::accumulate(total + 1, current, *total)
                << std::endl;
            total = current++;
        }
    }
    std::cout << std::accumulate(total + 1, current, *total)
        << std::endl;
}
 