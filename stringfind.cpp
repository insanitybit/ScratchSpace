#include <iostream>
#include <fstream>
using namespace std;

int main()
{

	// Create our input file using the file at path "./testfile"
	ifstream file("testfile");
	string f;
	// get the size of the file
	const size_t size = file.tellg();

	// reserve string size
	file.seekg(0, ios::end);   
	f.reserve(size);
	file.seekg(0, ios::beg);

	// move file buffer into string
	f.assign((istreambuf_iterator<char>(file)),
	            istreambuf_iterator<char>());

	// close file, we have a string now
	file.close();

	const string key = "XYZ";
	string newstr;
	size_t pos1 = 0;
	size_t pos2 = 0;

	// find the beginning of the word in 'key' from position 0
	pos1 = f.find(key, 0); // the 0 could also be pos1 because pos1 is 0 at first

	// find the end of the word, a space, in 'key' from position 1
	pos1 = f.find(" ", pos1);

	// increment past space
	pos1++;

	// find the end of the word after 'key' from pos1
	pos2 = f.find(" ", pos1);

	// create new string out of the substring of the two positions
	newstr = f.substr(pos1, (pos2 - pos1));

	// should print out the word after the key
	cout << newstr << endl;


	// to do you rhomework you should be pushing the newstr back into a vector, and doing this in a loop
	return 0;
}