// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "functions.h"

using namespace std;

int main()
{
	// array variable is a mem addr
	int nums[3] = { 1, 2, 3 };
	cout << nums << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int myInt = 20;
	cout << "\n - myInt - \n";
	cout << myInt << endl;

	passByValue(myInt);
	cout << "- after pass by value: "<< myInt << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	// define a ptr (save the addr) to int data
	int* intPtr = &myInt; // &var -- get addr of the var's data
	cout << "\n - intPtr - \n";
	cout << intPtr << endl;
	cout << *intPtr << endl; // deref -- go to the data at the addr in this ptr

	// passByPtr(intPtr);
	passByPtr(&myInt);
	cout << "- after pass by pointer: " << myInt << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	int* intHeapPtr = new int(30);
	cout << "\n - intHeapPtr - \n";
	cout << *intHeapPtr << endl;
	passByReference(*intHeapPtr);
	cout << "- after pass by ref: " << *intHeapPtr << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	while (true)
	{
		int* newHeapData = new int(100);
		//int a = 12;
		delete newHeapData; // reclaims data memory ONLY
		// without delete -- memory leak

		newHeapData = nullptr; // without this, dangling ptr
		if(newHeapData != nullptr)
			cout << *newHeapData << endl;
	}

}
