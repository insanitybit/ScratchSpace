#include "Threadpool.h"
#include <iostream>

using namespace std;

void empty_fake_work(size_t);


int main()
{
	const size_t run_count = 100000000;
	const auto core_count = thread::hardware_concurrency() - 1;


	auto empty_f = &empty_fake_work;

	Threadpool<decltype(empty_f)> voidpool(core_count, empty_f);
	voidpool.execute_atomic(run_count);
	voidpool.join();

	return 0;
}

void empty_fake_work(size_t j){
	size_t i = 0;
	for (i = 0; i < 1000000; ++i){
		i = i + 3 * 2;
		i--;
		i >> 2;
	}

	if(j % 1000 == 0)
		cout << j << " complete z = " << i << "\n";
}
