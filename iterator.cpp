#include <vector>
#include <iostream>

using namespace std;

int main()
{
	std::vector<size_t> v;
	auto it = v.begin();

	it--; // allowed

	cout << *it << endl; // segfault

	return 0;
}