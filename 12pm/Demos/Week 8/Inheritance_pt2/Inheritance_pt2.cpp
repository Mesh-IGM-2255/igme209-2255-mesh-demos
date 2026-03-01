// Inheritance_pt2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <vector>
using namespace std;

#include "Character.h"
#include "Cleric.h"

void wrapper();


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
	cout << "~~ CREATE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	Character parentObj = Character("Lacy");
	cout << endl;

	Cleric childObj = Cleric("Pax", "Attention");
	cout << endl;

	Character* parentPtrToChildObj = new Cleric("Aiden","Food");
	cout << endl;

	cout << "~~ PRINT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	parentObj.PrintData();
	parentObj.PrintType();
	cout << endl;

	childObj.PrintData();
	childObj.PrintType();
	cout << endl;

	parentPtrToChildObj->PrintData();
	parentPtrToChildObj->PrintType();
	cout << endl;

	cout << "~~ CLEAN UP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	delete parentPtrToChildObj;
	cout << endl;
}