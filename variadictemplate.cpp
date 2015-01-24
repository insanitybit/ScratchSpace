#include <iostream>
#include <functional>
#include "variadictem.h"

using namespace std;

void add(int a, int b, int c);


template<typename T, typename... Args>
void func(T, Args... args){
	add(args...);
}


int main()
{
	
func(1, 2, 3, 4);

variadictem<int> v(1, 2, 3, 4);


	return 0;
}

void add(int a, int b, int c){
	cout << a + b + c << endl;
}