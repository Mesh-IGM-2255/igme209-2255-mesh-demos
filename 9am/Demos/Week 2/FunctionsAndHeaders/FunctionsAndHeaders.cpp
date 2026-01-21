// FunctionsAndHeaders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"
//#include "functions.cpp" // NEVER!

// fwd decl
//int addFive(int num);

int main()
{
	int myNum = 12;
	std::cout << myNum << " + 5 = " << addFive(myNum) << std::endl;
}

/*
int addFive(int num)
{
	return num + 5;
}
*/


