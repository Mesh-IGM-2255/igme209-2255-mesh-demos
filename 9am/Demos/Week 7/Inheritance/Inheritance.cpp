// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Toy.h"
#include "Pet.h"
#include "Iguana.h"
#include <vector>

void wrapper();
void vectorExample();

int main()
{
	wrapper();

	if (_CrtDumpMemoryLeaks())
		cout << "\nMEMORY LEAKS!" << endl;
	else
		cout << "\nNo memory leaks. :)" << endl;
}

void wrapper()
{
	/*
	Pet shiro("Shiro", 8);
	Pet* shiroPtr = &shiro;
	Pet* lacyPtr = new Pet("Lacy", 6);

	shiro.print();
	shiroPtr->print();
	lacyPtr->print();
	delete lacyPtr;
	*/

	Iguana steve("Steve", 2);
	steve.print();
	steve.print();
	steve.print();
	cout << endl;

	Pet* myPet = &steve;
	myPet->print();
	myPet->print();

	steve.print();

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
	}

	for (short i = 0; i < myToys.size(); i++)
	{
		delete myToys[i];
	}
}

