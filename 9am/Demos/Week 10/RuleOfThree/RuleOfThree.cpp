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
	// Base demo setup
	Player* myPlayer = new Player(1, 2, 3);
	myPlayer->printInventory();
	myPlayer->SwapItem(1, 4);
	myPlayer->printInventory();

	// #1 -- need a custom destructor
	delete myPlayer;

	// #2 (& 3 ish) -- copy & assignment are SHALLOW default

	cout << endl;
	Player firstPlayer(4, 5, 6);
	//Player otherPlayer = firstPlayer; // assignment op
	Player otherPlayer(firstPlayer); // copy const
	firstPlayer.printInventory();
	otherPlayer.printInventory();
	otherPlayer.SwapItem(1, 42);
	firstPlayer.printInventory();
	otherPlayer.printInventory();


	// 3a -- copy constructor helps with assignment
	cout << endl;
	Player thirdPlayer = firstPlayer;
	firstPlayer.printInventory();
	thirdPlayer.printInventory();
	thirdPlayer.SwapItem(1, 101);
	firstPlayer.printInventory();
	thirdPlayer.printInventory();


	// 3b -- don't let self assignment happen
	cout << endl;
	firstPlayer = firstPlayer;
	firstPlayer.printInventory();


	// 3c -- careful with re-assignment
	cout << endl;
	thirdPlayer = firstPlayer;



}