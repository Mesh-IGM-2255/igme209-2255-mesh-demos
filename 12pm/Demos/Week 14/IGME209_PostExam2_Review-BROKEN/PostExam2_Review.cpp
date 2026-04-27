// PostExam2_Review.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Parent.h"
#include "Child.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

void test();

int main()
{
	test();

	if (_CrtDumpMemoryLeaks() == 0)
	{
		std::cout << "\n\nNo memory leaks detected." << std::endl;
	}
	else
	{
		std::cout << "\n\nMemory leaks detected!" << std::endl;
	}
}

// TODO: Cleanup memory appropriately
void test()
{
	std::cout << "\n~~~~~~~~~~~ Test Parent ~~~~~~~~~~~" << std::endl;
	Parent* parent = new Parent("AAA");
	parent->Display();

	std::cout << "\n~~~~~~~~~~~ Test Child ~~~~~~~~~~~" << std::endl;
	Child* child = new Child("BBB");
	child->Display();

	std::cout << "\n~~~~~~~~~~~ Test Child as Parent ~~~~~~~~~~~" << std::endl;
	Parent* childAsParent = new Child("CCC");
	childAsParent->Display();
}