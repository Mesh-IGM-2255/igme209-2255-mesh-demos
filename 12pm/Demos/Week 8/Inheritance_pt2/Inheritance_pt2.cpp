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
#include "Sorcerer.h"
#include "Multiclass.h"

void objTests();

void polymorphismTests();


int main()
{
	//objTests();
	polymorphismTests();

	if (_CrtDumpMemoryLeaks())
		cout << "\nMEMORY LEAKS!" << endl;
	else
		cout << "\nNo memory leaks. :)" << endl;
}

void polymorphismTests()
{
	cout << "~~ CREATE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	vector<Character*> npcs;
	npcs.push_back(new Character());
	cout << endl;

	npcs.push_back(new Cleric());
	cout << endl;

	npcs.push_back(new Sorcerer());
	cout << endl;

	npcs.push_back(new Multiclass());
	cout << endl;

	cout << "~~ PRINT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < npcs.size(); ++i)
	{
		npcs[i]->PrintData();
		npcs[i]->PrintType();
		cout << endl;
	}

	cout << "~~ DELETE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < npcs.size(); ++i)
	{
		delete npcs[i];
		cout << endl;
	}


}

void objTests()
{
	cout << "~~ CREATE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	Character parentObj = Character("Lacy");
	cout << endl;

	Cleric childObj = Cleric("Pax", "Attention");
	cout << endl;

	Character* parentPtrToChildObj = new Cleric("Aiden", "Food");
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