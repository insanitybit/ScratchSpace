#include <atomic>
#include <iostream>
#include <chrono>

using namespace std;

int main()
{

	// with no optimization, it appears that atomics are about 6~x slower than typical size_t to increment

	atomic<size_t> atom(0);
	// size_t atom = 0;

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;

	start = std::chrono::steady_clock::now();



	for (atom; atom < 10 * 100 * 1000; ++atom)
	{

	}


	end = std::chrono::steady_clock::now();
	elapsed_seconds = end-start;
	cout << "1m increment::  " << elapsed_seconds.count() * 1000 << "ms" << endl;


	return 0;
}