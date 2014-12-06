/*
g++ --std=c++11 ./hmdriver.cpp

This is just some homework assignment.
*/

#include <iostream>
#include <functional>
#include "hashmap.h"

using namespace std;

typedef function<size_t(string&)> fn;


size_t hash_fn(string&);

int main()
{
	fn hash = &hash_fn;
	size_t size = 23;
	size_t index;
	
	hashmap<fn, string> map(hash, size);

	string s;
	for(size_t i = 0; i < 15; ++i)
	{
		cout << "Enter in a string to store in your map\n";
		cin >> s;
		map.store(s); 
	}

	cout << "=================================================================\n";

	for (size_t i = 0; i < map.size(); ++i)
	{
		//if(map.at(i) != "") // show both empty and filled positions
			cout << map.at(i) << endl;
	}

	while(s != "stop"){
		cout << "Enter a word to query\nEnter 'stop' to terminate.\n";
		cin >> s;
		if((index = map.lookup(s)) != -1){
			cout << s << " found at index " << index << "\n";
		} else {
			cout << s << " not found\n";
		}

	}

	return 0;
}

size_t hash_fn(string& str){
	size_t pos;
	auto fchar = str.begin();
	auto echar = str.end();
	pos = (static_cast<size_t>(*fchar) + static_cast<size_t>(*echar)) % 23;
}