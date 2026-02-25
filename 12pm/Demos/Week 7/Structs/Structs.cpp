// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <ctime>

#include <iostream>

#include "Point.h"

using namespace std;

void mainWrapper();

void passByValue(Point p);

int main()
{
	srand(time(NULL));

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
	Point p1("p1", 3, 4);
	Point p2("p2", - 1, 40);
	Point origin("origin",0, 0);

	p1.print();
	cout << endl;
	p2.print();
	cout << endl;
	origin.print();
	cout << endl;

	Point::distance(origin, p1);
	Point::distance(origin, p2);

	// WILL NOT WORK until we teach you copy constructors
	//passByValue(p1);
}

void passByValue(Point p)
{
	p.print();
	cout << endl;
}
