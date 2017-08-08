#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> *alloc()
{
	auto p = new vector<int>;
	return p;
}

void read(vector<int> *p)
{
	for (int s; cin >> s; p->push_back(s));
}

void print(vector<int> *p)
{
	for (auto i : *p)
		cout << i << " ";
	cout << endl;
}

int main()
{
	auto p = alloc();
	read(p);
	print(p);
	delete p;
}