#include <fstream>
#include <iterator>
#include <string>

using std::string;
using std::ifstream; using std::ofstream;


void sep_odd_even(const string &input, const string &even, const string &odd)
{
    ofstream even_file(even), odd_file(odd);
    ifstream input_file(input);
    
    std::ostream_iterator<int> even_iter(even_file, "\n"), odd_iter(odd_file, " ");
    std::istream_iterator<int> in_iter(input_file), eof;

    // more cpp use for_each
    while (in_iter != eof) {
        if (*in_iter % 2)
            odd_iter = *in_iter;
        else
            even_iter = *in_iter;
        ++in_iter;
    }

}


int main()
{
    sep_odd_even("input.txt", "even.txt", "odd.txt");
}