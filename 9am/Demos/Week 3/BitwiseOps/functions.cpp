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