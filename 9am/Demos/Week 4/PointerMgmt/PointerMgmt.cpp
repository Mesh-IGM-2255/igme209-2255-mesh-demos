// PointerMgmt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// in iostream too, but good to know in case we aren't using iostream
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

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

	//_CrtDumpMemoryLeaks();

	if (_CrtDumpMemoryLeaks())
	{
		cout << "MEMORY LEAKS - CHECK DEBUG OUTPUT WINDOW!" << endl;
	}
	else
	{
		cout << "NO LEAKS DETECTED" << endl;
	}


}

