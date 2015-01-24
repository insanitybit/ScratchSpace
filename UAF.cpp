#include <iostream>

using namespace std;

void free_x(int *);

int main()
{
	int * x = new int[2];
	x[0] = 5;
	x[1] = 2;

	free_x(x);	// free x

	// use x
	cout << x[0] + x[1] << endl;

	return 0;
}

void free_x(int * x){

	delete[] x;
}