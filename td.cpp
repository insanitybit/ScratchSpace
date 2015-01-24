#include <iostream>
#include "tclass.h"

using namespace std;

int main(int argc, char const *argv[])
{

	// WORKS
	tclass<int, int> a;
	int x = 5;
	int y = 6;

	a.example(x, y);

	// nope

	tclass<int, int> c;

	c.example(x);

	return 0;
}