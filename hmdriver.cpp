/*
Colin O'Brien
November 24th 2014
g++ --std=c++11 ./hmdriver.cpp


*/

#include <iostream>
#include <functional>
#include "hashmap.h"

using namespace std;

typedef function<size_t(string&)> fn;

// This is the hash function that we will be passing to our generic hash map class
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

// hash function as described by angel page
size_t hash_fn(string& str){
	size_t pos;
	auto fchar = str.cbegin();
	auto echar = (str.end() - 1);
	pos = (static_cast<size_t>(*fchar) + static_cast<size_t>(*echar)) % 23;
	return pos;
}