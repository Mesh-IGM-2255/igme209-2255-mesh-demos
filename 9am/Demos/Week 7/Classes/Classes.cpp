// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <ctime>

#include <iostream>
#include "Player.h"

using namespace std;

void mainWrapper();

int main()
{
	srand(time(NULL));
	mainWrapper();

	//Player tmp;
	//tmp.print();

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
	Player p1;
	p1.print();
	cout << endl;

	Player p2("Lacy", 3);
	p2.print();

	Player* p3ptr = new Player();
	p3ptr->print();

	delete p3ptr;

}