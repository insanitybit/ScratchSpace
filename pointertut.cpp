#include <iostream>

// simple pointer demonstration

using namespace std;

int main()
{
	// i is an integer holding the value 5
	int i = 5;
	// p is an integer pointer. Neither the value OF p (the address it points to) NOR the value AT *p (the value it points to)
	// can be changed
	const auto * const p = &i;

	cout << "address of i is \t\t\t\t" << &i << endl;

	cout << "value of p is \t\t\t\t\t" <<  p << endl;

	cout << "value of i is \t\t\t\t\t" <<  i << endl;

	cout << "value of * p (what p points to) is \t\t" << *p << endl;

	cout <<"address of p is \t\t\t\t"<< &p << endl;


	// pointer arithmetic
	cout << "\n\n";


	int arr[5] = {0, 1, 2, 3, 4};

	const int * ip = &arr[0]; // the const means it won't change the value at *ip
	// const int * const ip = &arr[0]; VIOLATION because the value of ip is changed later in the program

	cout << "element 0 is " << *ip << endl;


	cout << "\nEntering For loop \n\n";
	for (int i = 0; i < 5; ++i)
	{
		cout << "element " << i << " is " << *ip++ << endl;
	}

	// Currently ip is pointing to the array at index [5], which does not exist. It is pointing outside of the array.

	ip--; // this points ip one position before its previous position, which is arr[4];

	cout << "\nEntering While Loop\n\n";
	while(*ip != 0){
		cout << "*ip points to " << *ip << endl;
		ip--;
	}

	cout << "ip is now pointing at the value 0\n";
	cout << *ip << endl;

	return 0;
}