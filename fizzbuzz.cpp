#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	for (int i = 1; i <= 100; ++i)
	{
		cout << i << "\t";
		if(((i % 3) == 0) && (i % 5) == 0){
			cout << " fizzbuzz";
		} else if((i % 5) == 0){
			cout << " buzz";
		} else if((i % 3) == 0){
			cout << " fizz";
		}
		cout << "\n";
	}

	return 0;
}