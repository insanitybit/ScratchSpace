#include <iostream>

// simple pointer demonstration

using namespace std;

int main()
{
	// i is an integer holding the value 5
	int i = 5;

	const auto const p = &i;

	cout << "address of i is \t\t\t\t" << &i << endl;
	cout << "value of p is \t\t\t\t\t" <<  p << endl;
	cout << "value of i is \t\t\t\t\t" <<  i << endl;
	cout << "value of * p (what p points to) is \t\t" << *p << endl;
	cout << "address of p is \t\t\t\t" << &p << endl;

	// pointer arithmetic
	cout << "\n\n";

	
	int arr[5] = {0, 1, 2, 3, 4};

	const int * ip = &arr[0]; 

	cout << "element 0 is " << *ip << endl;

	cout << "\nEntering For loop \n\n";

	for (int i = 0; i < 5; ++i)
	{
		cout << "element " << i << " is " << *ip << endl;
		ip++;
	}

	ip--; 

	cout << "\nEntering While Loop\n\n";
	while(*ip != 0){
		cout << "*ip points to " << *ip << endl;
		ip--;
	}
	
	cout << "ip is now pointing at the value 0\n";
	cout << *ip << endl;

	return 0;
}