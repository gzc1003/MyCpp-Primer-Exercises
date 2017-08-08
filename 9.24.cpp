#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;
#include <stdexcept>

int main()
{
    vector<int> v;
    try {
        cout << v.at(0) << endl;
    } catch (std::out_of_range err) {
        std::cerr << err.what() << " at " << __LINE__
            << " in file " << __FILE__ << endl;
    }
    /*cout << v[0] << endl;
    cout << v.front() << endl;
    cout << *v.begin() << endl;*/
    return 0;
}