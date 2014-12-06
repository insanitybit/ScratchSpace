// Simple test for tight loops with different sizes

#include <chrono>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;

	uint32_t size32 = 1000;
	size_t sizet = 1000;

	start = std::chrono::steady_clock::now();

	for (size_t i = 0; i < sizet; ++i)
	{

	}



	end = std::chrono::steady_clock::now();
	elapsed_seconds = end-start;

	cout << "Open Log_File::  " << elapsed_seconds.count() * 1000 << "ms" << endl;
	



	return 0;
}