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
	int myInt = 40;
	int* myIntPtr = &myInt;

	int nums[3] = { 1, 2, 3 };

	// delete myIntPtr; // BAD

	myIntPtr = nullptr; // ok!

	myIntPtr = new int(50); // HEAP
	delete myIntPtr; // without this - memory leak
	myIntPtr = nullptr; // without this -- dangling pointer

	// new int(50); // instant memory leak

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //int* memleak = new int(42);

	//string thing = "Hello World";
	useString();

	arrPtrDemo();

	//_CrtDumpMemoryLeaks();

	if (_CrtDumpMemoryLeaks())
	{
		cout << "MEMORY LEAKS - CHECK DEBUG OUTPUT WINDOW!" << endl;
	}
	else
	{
		cout << "NO LEAKS DETECTED" << endl;
	}

	//int* memleak = new int(42);


	//delete memleak;
}

void useString()
{
	string thing = "Hello World";
	//string* thing = new string("Hello World");
}

void arrPtrDemo()
{
	int* heapArr = createArray(5);
	int newArray[10]; // stack
	for (int i = 0; i < 10; i++)
	{
		// have to copy element by element & adjust to make bigger/smaller
	}
	delete[] heapArr;
}

int* createArray(int arrSize)
{
//	const int arrSize = 5;
	//int myArray[arrSize];
	//int* myArray = new int[arrSize];
	return new int[arrSize] {1, 2, 3};
}

