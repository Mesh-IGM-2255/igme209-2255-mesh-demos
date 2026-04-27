// PracticalDryRun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "functions.h"
#include <iostream>

using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

int main()
{
	example1();
	example2();
	testTemplate();

	if (_CrtDumpMemoryLeaks())
	{
		cout << "\n\nMemory leaks detected!" << endl;
	}
	else
	{
		cout << "\n\nNo memory leaks detected." << endl;
	}
}
