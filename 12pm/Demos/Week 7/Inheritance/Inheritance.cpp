// Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include "Toy.h"
#include "Pet.h"
#include "Dog.h"
#include <vector>

void wrapper();
void vectorExample();

int main()
{
	//vectorExample();
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
	}

	for (short i = 0; i < myToys.size(); i++)
	{
		delete myToys[i];
	}
}

void wrapper()
{
	Dog pax("Pax");

	pax.talk();
	cout << endl;

	Pet* myDog = &pax;
	myDog->talk();
	cout << endl;

	myDog->talk();
	cout << endl;

	pax.talk();
	cout << endl;
}