#include <queue>
using std::priority_queue;
#include <iostream>
using std::cout; using std::endl;

int main()
{
    priority_queue<int> pq;
    for (int i = 0; i != 10; ++i)
        pq.push(i);
    cout << pq.top() << endl;   // 9
    
    return 0;
}