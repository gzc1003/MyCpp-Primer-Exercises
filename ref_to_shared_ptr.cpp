#include <memory>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<shared_ptr<int>> vec;
	vec.push_back(make_shared<int>(42));
	cout << "vec[0].use_count = "<<vec[0].use_count() << endl;

	auto &rp = vec[0];
	cout << "rp.use_count() = " <<rp.use_count() << endl;

	auto p = rp;
	cout << "p.use_count() = " << p.use_count() << endl;
}