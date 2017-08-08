#include <memory>
#include <vector>
#include <iostream>

using namespace std;

typedef shared_ptr<vector<int>> Ptr;

Ptr alloc()
{
	return make_shared<vector<int>>();
}

void read(Ptr p)
{
	for (int s; cin >> s; p->push_back(s));
}

void print(Ptr p)
{
	for (auto i : *p)
		cout << i << " ";
	cout << endl;
}

int main()
{
	Ptr p = alloc();
	read(p);
	print(p);
}
