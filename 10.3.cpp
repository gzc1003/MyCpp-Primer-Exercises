#include <numeric>
#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include <list>
using std::list;
#include <iterator>

int main()
{
    vector<int> vec{ 1,2,3,4,5 };
    cout << std::accumulate(vec.cbegin(), vec.cend(), 0) << endl;
    
    vector<double> vec2{ 1.1, 2.2, 3.3, 4.4 };
    auto sum2 = std::accumulate(vec2.cbegin(), vec2.cend(), 0);
    cout << sum2 << endl;

    vector<const char*> roster1{ "Tom", "Jack"};
    list<const char*> roster2{ "Tom", "Jack"};
    cout << std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin());
    
    // play with multidimensional array
    const char ca[3][2] = { "A", "B", "C" };
    const char cb[3][2] = { "A", "B", "C" };
    vector<const char*> roster3(std::begin(ca), std::end(ca));
    list<const char*> roster4(std::begin(ca), std::end(ca));
    
    const char(*p)[2] = std::begin(ca);
    auto p2 = std::begin(ca);

    return 0;
}