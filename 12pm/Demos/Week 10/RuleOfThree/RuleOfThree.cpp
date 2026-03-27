// RuleOfThree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

// Rule of Three -- guidelines for creating classes that maintain a resource that was
// allocated external to the class.

#include <iostream>
using namespace std;

#include "Player.h"

void playerTests();

int main()
{
	playerTests();

	if (_CrtDumpMemoryLeaks())
		std::cout << "\nMemory leaks?!" << std::endl;
	else
		std::cout << "\nNo leaks :)" << std::endl;

	return 0;
}

void playerTests()
{
	Player myPlayer(1, 2, 3);
	myPlayer.printInventory();
	myPlayer.SwapItem(2, 10);
	myPlayer.printInventory();

	Player* playerPtr = new Player(1, 2, 3);
	delete playerPtr;

	// #1 - external data isn't automatical cleaned up

	// #2
	cout << endl;
	Player firstPlayer(4, 5, 6);
	Player otherPlayer(firstPlayer); // default copy is a SHALLOW copy

	firstPlayer.printInventory();
	otherPlayer.printInventory();
	otherPlayer.SwapItem(2, 2222);
	firstPlayer.printInventory();
	otherPlayer.printInventory();

	// #3a -- assignment op == default SHALLOW copy
	Player anotherPlayer = firstPlayer; 

	// #3b
	cout << endl;
	anotherPlayer = anotherPlayer; 

	// #3c
	cout << endl;
	anotherPlayer = otherPlayer;


}