// PointerMgmt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// in iostream too, but good to know in case we aren't using iostream
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

void useString();

void arrPtrDemo();
int* createArray(int arrSize);

int main()
{
	int myInt = 40; // s
	int* myIntPtr = &myInt; // s
	// delete myIntPtr; // BAD

	int nums[3] = { 1, 2, 3 }; // s

	int* otherPtr = new int(12); // h
	delete otherPtr;
	otherPtr = nullptr;

	// new int(12); // h -- instant leak

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	int* memleak = new int(42);
	delete memleak;

	//string thing = "Hello";
	useString();

	// DO THIS LAST
	//_CrtDumpMemoryLeaks();

	arrPtrDemo();

	if (_CrtDumpMemoryLeaks()) // true if != 0
	{
		cout << "*Potential* MEMORY LEAKS - CHECK DEBUG OUTPUT WINDOW!" << endl;
	}
	else
	{
		cout << "NO LEAKS DETECTED" << endl;
	}

	//delete memleak;

	//int* otherleak = new int(45);

	// string on the stack cleans its mem up at the end
}

void useString()
{
	string thing = "Hello";
}

void arrPtrDemo()
{
	int newArray[5]; // s
	int* newArr = createArray(5);
	delete[] newArr;
}

int* createArray(int arrSize)
{
	//int myArray[arrSize];
	//int* myArray = new int[arrSize];
	//return myArray;
	return new int[arrSize];
}