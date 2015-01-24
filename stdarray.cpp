#include <array>
#include <iostream>

using namespace std;

int main()
{
	array<int, 4> arr {1, 3, 5, 7};

	// iterators
	const auto beg = arr.cbegin();
	const auto end = arr.cend();

	cout << "Iterators behave the same way pointers do" << endl;

	cout << "Dereferencing beg + 0 " << *beg << endl;
	cout << "Dereferencing beg + 1 " << *(beg+1) << endl;
	cout << "Dereferencing beg + 2 " << *(beg + 2)<< endl;
	cout << "Dereferencing end - 1 " << *(end - 1) << endl; 


	cout << "\n\nPrinting each element in array\n\n";

	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr.at(i) << endl;
		//cout << arr[i] << endl;
	}


	cout << "\n\nPrinting using iterator loop\n\n";

	for (auto i = beg; i != end; ++i)
	{
		cout << *i << endl;
	}

	// //typical iterator loops look more like this
	// for (auto i = arr.cbegin(); i != arr.cend(); ++i)
	// {
		
	// }


	cout << "\n\nPrinting using range for loop\n\n";

	for(const auto& a : arr) // because 'a' is not actually incremented, it can be made const
		cout << a << endl;

	return 0;
}