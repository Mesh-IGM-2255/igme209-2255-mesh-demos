// FunctionPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include "otherFile.h"
using namespace std;

bool descending(int a, int b);

int main()
{
	// data pointer
	int num = 4;
	int* numPtr = &num;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	thing();
	cout << thing << endl;

	cout << addNumbers(1, 1) << endl;
	cout << addNumbers << endl;

	// make variables to hold ptrs to the functions
	// return_type(* varName)(param_types)
	void(*thingFP)();
	int(*twoNumsFP)(int, int);

	thingFP = thing;
	twoNumsFP = multiplyNumbers;

	thingFP();
	cout << twoNumsFP << endl;
	cout << twoNumsFP(2, 3) << endl;

	runTwoNumsFunction(addNumbers, 2, 3);
	runTwoNumsFunction(multiplyNumbers, 2, 3);

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// let the user pick what to do
	int choice = 0;
	twoNumsFuncType funcPtr;

	cout << "0: add, 1: multiply" << endl;
	cin >> choice;
	if (choice) // 0 is false
	{
		funcPtr = multiplyNumbers;
	}
	else
	{
		funcPtr = addNumbers;
	}
	runTwoNumsFunction(funcPtr, 30, 40);

	// A bit of a contrived example. Could refactor so we have what we need at compile time.
	
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	const uint ARR_SIZE = 5;
	int intArray[ARR_SIZE] = { 6, 8, 1, 3, 7 };

	//std::sort(intArray, intArray + ARR_SIZE);
	std::sort(intArray, intArray + ARR_SIZE, descending);

}


bool descending(int a, int b)
{
	return a > b; // if a is bigger than b, true that it's descending
}
