// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Toy.h"
#include <vector>

void wrapper();
void vectorExample();

int main()
{
    std::cout << "Hello World!\n";
}

int main()
{
	wrapper();

	if (_CrtDumpMemoryLeaks())
		cout << "\nMEMORY LEAKS!" << endl;
	else
		cout << "\nNo memory leaks. :)" << endl;
}

void vectorExample()
{
	vector<Toy*> myToys = vector<Toy*>();
	for (short i = 0; i < 3; i++)
	{
		myToys.push_back(new Toy()); // Add
	}

	for (short i = 0; i < myToys.size(); i++)
	{
		myToys[i]->Print(); // Can still access like an array
		delete myToys[i];
	}
}

void wrapper()
{
}