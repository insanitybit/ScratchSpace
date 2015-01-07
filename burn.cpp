#include "Threadpool.h"
#include <iostream>
#include <array>
#include <mutex>

using namespace std;

void empty_fake_work(size_t);


int main()
{
	const size_t run_count = 1000000000000;
	const auto core_count = thread::hardware_concurrency() - 1;


	auto empty_f = &empty_fake_work;

	Threadpool<decltype(empty_f)> voidpool(core_count, empty_f);
	voidpool.execute_atomic(run_count);
	voidpool.join();

	return 0;
}

void empty_fake_work(size_t j){
	for (size_t i = 0; i < 10000000000; ++i){
		i = i + i * 2;
		if(i % 2 != 0)
			i--;
		else
			i -= 2;
	}

	if(j % 1000000 == 0)
		cout << j << " complete\n";
}
