#include <array>
#include <iostream>
#include <chrono>

using namespace std;

int main()
{


	// std::chrono::time_point<std::chrono::steady_clock> start, end;
	// std::chrono::duration<double> elapsed_seconds;

	// start = std::chrono::steady_clock::now();


	array<size_t, 10 * 100 * 1000> arr;

	for (size_t i = 0; i < arr.size(); ++i)
	{
		arr[i] = i;
	}



	// size_t arr[10 * 100 * 1000];


	// for (size_t i = 0; i < 10 * 100 * 1000; ++i)
	// {
	// 	arr[i] = i;
	// }



	// end = std::chrono::steady_clock::now();
	// elapsed_seconds = end-start;
	// cout << "1m insertions::  " << elapsed_seconds.count() * 1000 << "ms" << endl;

	return 0;
}