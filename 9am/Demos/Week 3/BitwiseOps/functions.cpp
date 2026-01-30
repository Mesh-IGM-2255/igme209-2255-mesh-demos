// Include <bitset> to see binary version
#include <bitset>
#include <iostream>

#include "functions.h"
using namespace std;

void _div()
{
	cout << "\n---------------------------------------------------------------------------------------------\n\n";
}

// helpers to print shorts in decimal and binary
void printOneShort(const char label[], short num)
{
	cout << label << " \t\t\tDecimal: " << num;
	cout << "\t\tBinary: " << bitset<16>(num) << endl;
	// << bitset<16>(a) ---> <#> number of bits to show 
}


void printTwoShorts(short a, short b)
{
	printOneShort("A", a);
	printOneShort("B", b);
}


bool resolveCollision(short objectMask, short collisionLayer)
{
	// bitwise AND will tell us about any overlap between two sets of bits
	// we want to know if the layer we are checking overlaps the mask of info about layers that can collide with the object
	//return (objectMask & collisionLayer) != 0; // --> a boolean -- but that overkill. 
	//Just return the result of the AND because C++ interprets 0 as false and anything else as true
	return objectMask & collisionLayer;
}