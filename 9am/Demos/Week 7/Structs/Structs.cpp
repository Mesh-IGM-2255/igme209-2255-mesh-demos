// Structs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
using namespace std;

#include "Point.h"

void mainWrapper();

void printPoint(Point thing);

int main()
{
	mainWrapper();

	if (_CrtDumpMemoryLeaks())
	{
		cout << "\nPOSSIBLE MEMORY LEAKS - CHECK DEBUG OUTPUT WINDOW!" << endl;
	}
	else
	{
		cout << "\nNo memory leaks detected." << endl;
	}
}

void mainWrapper()
{
	Point p1("p1", 12, 34);
	Point p2("p2", -3, -5);
	Point origin("origin", 0, 0);

	p1.print();
	cout << endl;

	p2.print();
	cout << endl;

	origin.print();
	cout << endl;

	Point::distance(p1, origin);

	// pass by value of classes & structs won't work until we
	// learn copy constructors!!!!
	//printPoint(origin);

}

void printPoint(Point thing)
{
	thing.print();
}

