#include <vector>
using std::vector;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    vector<int> v1;
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;

    for (decltype(v1.size()) i = 0; i != 24; ++i)
        v1.push_back(i);
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;

    v1.reserve(50);
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;

    while(v1.size() != v1.capacity())
        v1.push_back(0);
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;

    v1.push_back(0);
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;

    v1.shrink_to_fit();
    cout << "v1 size: " << v1.size() << endl;
    cout << "v1 capacity: " << v1.capacity() << endl;

    return 0;
}