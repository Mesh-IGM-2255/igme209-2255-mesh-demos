// BitwiseOps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"

int main()
{
	short test = 4;
	printOneShort("Testing", test);
	_div();

	short test2 = 11110000;
	printOneShort("Bad Init", test2);
	_div();

	// Define in binary -- 0b at the start
	short a = 0b11110000; // 240
	short b = 0b10101010; // 170
	printTwoShorts(a, b);
	_div();
}
