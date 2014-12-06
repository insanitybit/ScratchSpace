#ifndef HASHMAP_H
#define HASHMAP_H
#include <iostream>
#include <vector>

// Simple map class for generic types that uses any custom hash function

template<class fnc, class data>
class hashmap
{
	public:
		hashmap(fnc&, size_t);      // Constructor takes in number of elements to allocate to hashmap
		size_t store(data&);
		size_t size();
		data at(size_t);
		ssize_t lookup(data&);
		size_t count(data&);

	private:
		fnc fn;
		std::vector<data> map;
		std::vector<bool> shadow;	// shadow is used so that we can generically track insertions
									// std::bitset won't work here, but using a unique_pointer would
};

// constructor takes in generic function type, and size. hashmap should be in valid state after constructor.
template<class fnc, class data>
hashmap<fnc,data>::hashmap(fnc& fn, size_t size){
	map.resize(size);
	shadow.resize(size, false);
	this->fn = fn;
}

// The store function uses whatever hash function is provided to create an 'index'
// It then checks if the generic data at map[index] is empty repeatedly until it finds an empty index
template<class fnc, class data>
size_t hashmap<fnc,data>::store(data& input){
	size_t index;

	index = fn(input);

	while(shadow[index]){
		index++;
		if(index >= map.size()) // If we hit the last space, start from index 0 and continue
			index = 0;
	}

	map[index] = input;
	shadow[index].flip();
	// = true;
}

// lookup() takes in template type data 's' and returns the index of the first position of 's'
// returns -1 if not found
template<class fnc, class data>
ssize_t hashmap<fnc,data>::lookup(data& s){
	size_t index;
	index = fn(s);

	for (size_t i = index; i < map.size(); ++i)
	{
		if(map[i] == s)
			return i;
	}

	return -1;
}

// size() returns the size of the internal map vector
template<class fnc, class data>
size_t hashmap<fnc,data>::size(){
	return map.size();
}

// returns type 'data' at position 'index' of internal map
template<class fnc, class data>
data hashmap<fnc,data>::at(size_t index){
	return map.at(index);
}


// unused function but if you want to count the number of a specific item in the map
// this is how you'd do it
template<class fnc, class data>
size_t hashmap<fnc,data>::count(data& s){
	size_t count = 0;

	for (size_t i = 0; i < map.size(); ++i)
	{
		if(map[i] == s)
			count++;
	}
	return count;
}

#endif