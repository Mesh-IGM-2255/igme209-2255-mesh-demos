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

void ruleOneDemo();
void ruleTwoDemo();
void ruleThreeDemo();
void fullPlayerTests();

int main()
{
	// Show which rules are currently in the demo:
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Current rules in the demo:" << endl;
	cout << "Rule 1 - Custom Destructor: ";
	#ifdef R1
		cout << "ON" << endl;
	#else
		cout << "OFF" << endl;
	#endif

	cout << "Rule 2 - Custom Copy Constructor: ";
	#ifdef R2
		cout << "ON" << endl;
	#else
		cout << "OFF" << endl;	
	#endif

	cout << "Rule 3 - Custom Assignment Operator: ";
	#ifdef R3
		cout << "ON" << endl;
	#else
		cout << "OFF" << endl;
	#endif
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	ruleOneDemo();
	ruleTwoDemo();
	ruleThreeDemo();

	//fullPlayerTests();

	if (_CrtDumpMemoryLeaks())
		std::cout << "\nMemory leaks?!" << std::endl;
	else
		std::cout << "\nNo leaks :)" << std::endl;

	return 0;
}

// If your class manages a resource that was allocated outside of the class, you need to follow the Rule of Three:
// If you don't follow these, you can get memory leaks, double deletes, and other bad things.

// 1. Custom Destructor
void ruleOneDemo()
{
	// Creating 1 object of the Player class is fine, as long as it has a custom destructor
	cout << "\n~~~~~~~~~~~~~~ Rule 1 ~~~~~~~~~~~~~~" << endl;
	Player p1("p1",1, 2, 3);
	p1.printInventory();

	// Destructor is called when ruleOne goes out of scope. If we don't have a custom destructor, 
	// then the memory allocated for the inventory on the heap will never be freed, which is bad.
	cout << "\nCleanup..." << endl;
}

// 2. Custom Copy Constructor
void ruleTwoDemo()
{
	cout << "\n~~~~~~~~~~~~~~ Rule 2 ~~~~~~~~~~~~~~" << endl;

	cout << "\nCreate p1" << endl;
	Player p1("p1",1, 2, 3);
	p1.printInventory();

	cout << "\nCreate p2 as a copy of p1 via =" << endl;
	Player p2 = p1; // copy constructor is called here because we're creating a new object 
				    // and initializing it with an existing one
	p2.printInventory();

	cout << "\nCreate p3 as a copy of p1 via copy constructor" << endl;
	Player p3(p1); 
	p3.printInventory();

	// If only a shallow copy is made, then p1, p2, and p3 will all point to the same inventory on the heap
	// and we get multiple deletes of the same memory when they go out of scope, which is bad.
	cout << "\nCleanup..." << endl;
}

// 3. Custom Assignment Operator
void ruleThreeDemo()
{
	cout << "\n~~~~~~~~~~~~~~ Rule 3 ~~~~~~~~~~~~~~" << endl;

	cout << "\nCreate p1" << endl;
	Player p1("p1", 1, 2, 3);
	p1.printInventory();

	cout << "\nCreate p2" << endl;
	Player p2("p2", 4, 5, 6);
	p2.printInventory();

	cout << "\nAssign p1 to p2 with =" << endl;
	p2 = p1; // assignment operator is called here because we're assigning an existing object to another existing object
	p2.printInventory();

	// If only a shallow copy is made, then p1 and p2 will point to the same inventory on the heap
	// and we get multiple deletes of the same memory when they go out of scope, which is bad.
	cout << "\nCleanup..." << endl;
}

// Comment out different ifdefs in Player.h to see the different problems that arise when we don't follow the Rule of Three



void fullPlayerTests()
{
	// Base demo setup
	Player myPlayer("myPlayer", 1, 2, 3);
	myPlayer.printInventory();
	myPlayer.SwapItem(1, 4);
	myPlayer.printInventory();

	// Problem 1: obj is on the stack, but it has data on the heap.
	// --> Need a custom destructor

	// Problem 2: Everything has a copy constructor by default, 
	// but it's a SHALLOW copy.
	// --> Need a custom copy constructor so we don't have
	//     two objects on the stack pointing to the same data on 
	//     the heap & thus deleting it twice.
	cout << endl;
	Player otherPlayer = myPlayer;
	otherPlayer.SwapItem(1, 99);
	myPlayer.printInventory();
	otherPlayer.printInventory();

	// Problem 3: I want to make 2 objects equal to each other
	// but I don't want them to point to the same data on the heap.
	// --> Need a custom assignment operator
	cout << endl;
	otherPlayer = myPlayer;
	myPlayer.printInventory();
	otherPlayer.printInventory();

	// Problem 3a: copying ourselves
	// --> Need to check for self-assignment
	cout << endl;
	otherPlayer = otherPlayer;
	otherPlayer.printInventory();

	// Other gotchas
	Player* p1 = new Player("p1",1, 2, 3);
	//Player p2 = p1; // can't copy a ptr to a non-ptr
	Player p2 = *p1; // deref to get a copy 
	Player p2a = Player(*p1);// or explicitly use copy constructor

	Player* p3 = new Player("p3",4, 5, 6);
	//p1 = p3; // creates a dangling pointer
	*p1 = *p3; // deref both to get a copy

	delete p1; 
	delete p3;

	// Let things go out of scope
	cout << endl;
}