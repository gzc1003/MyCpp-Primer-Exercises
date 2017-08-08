#include <iostream>
using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <deque>
using std::deque;


int main()
{
    vector<int> v = { 1,2,3,4,5 };
    auto iter = v.begin();
    auto mid = v.begin() + v.size() / 2;
    cout << "capacity: " << v.capacity() << endl;
    cout << "iter pos: " << iter - v.begin() << endl;
    cout << "mid pos: " << mid - v.begin() << endl;

    v.insert(v.begin()+1, 0);
    cout << "capacity: " << v.capacity() << endl;
    cout << "iter pos: " << iter - v.begin() << endl;
    cout << "mid pos: " << mid - v.begin() << endl;

    deque<int> dq = { 1,2,3,4,5 };
    auto end = dq.end();
    cout << "end pos: " << end - dq.begin() << endl;
    dq.push_front(0);
    cout << "end pos: " << end - dq.begin() << endl;

    return 0;
}