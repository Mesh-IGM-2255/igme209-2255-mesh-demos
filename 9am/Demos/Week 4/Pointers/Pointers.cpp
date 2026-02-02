// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
	int myInt = 20; // on the stack
	cout << "\nmyInt" << endl;
	cout << myInt << endl;
	cout << &myInt << endl; // addr of the data on the stack

	int* intPtr = new int(30); // "int*" -- addr to an int
	cout << "\nintPtr" << endl;
	cout << intPtr << endl;
	cout << *intPtr << endl; // * BEFORE var --- go to the addr
	delete intPtr;
	intPtr = nullptr;

	int* ptrToMyInt = &myInt;
	cout << "\nptrToMyInt" << endl;
	cout << ptrToMyInt << endl;
	cout << *ptrToMyInt << endl;
	// this is a ptr to stack data. Do NOT delete it!


	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	int* newPtr = nullptr;
	//while (true)
	{
		newPtr = new int(42);
		delete newPtr; // just a delete
					   // without this - memory leak
		//cout << *newPtr << endl;
		newPtr = nullptr; // without this - dangling ptr
	}


	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	int origNum = 1;
	passByValue(origNum);
	cout << "final num: " << origNum << endl;

	origNum = 1;
	passByPtr(&origNum); // & -- get addr of
	cout << "final num: " << origNum << endl;

	origNum = 1;
	passByReference(origNum); 
	cout << "final num: " << origNum << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
