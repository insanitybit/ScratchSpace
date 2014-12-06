#include <iostream>
#include <chrono>

using namespace std;

// demonstration of cache locality.

int main()
{
	const size_t rows_size = 100;
	const size_t cols_size = rows_size;
	size_t matrix[rows_size][cols_size];

	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<double> elapsed_seconds;

	cout << "Going through the cache friendly way:" << endl;

	start = std::chrono::steady_clock::now();

	for (size_t i = 0; i < rows_size; ++i)
	{
		for (size_t j = 0; j < cols_size; ++j)
		{
			matrix[i][j] = i;
		}
	}

	end = std::chrono::steady_clock::now();
	elapsed_seconds = end - start;

	cout << "matrix::  " << elapsed_seconds.count() * 1000 << "ms" << endl;

	cout << endl;

	cout << "Going through the not so cache friendly way" << endl;

	start = std::chrono::steady_clock::now();

	for (size_t i = 0; i < rows_size; ++i)
	{
		for (size_t j = 0; j < cols_size; ++j)
		{
			matrix[j][i] = i;
		}
	}

	end = std::chrono::steady_clock::now();

	elapsed_seconds = end-start;
	cout << "matrix::  " << elapsed_seconds.count() * 1000 << "ms" << endl;
	cout << matrix[0][0];

	return 0;
}