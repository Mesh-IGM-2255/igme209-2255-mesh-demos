// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
#include <string>

#include "Person.h"
#include "SmartPersonPointer.h"
#include "SmartPointer.h"

using namespace std;

void ptrReview();
Person* getPerson();
void customSmartPtr();

int main()
{
	//ptrReview();
	customSmartPtr();

	if (_CrtDumpMemoryLeaks())
		std::cout << "\nMemory leaks?!" << std::endl;
	else
		std::cout << "\nNo leaks :)" << std::endl;

	return 0;
}

void ptrReview()
{
	// If we create a default person on the STACK, not a big deal. It'll go away when the function ends
	Person person("Shiro");
	person.printName();

	// If we make the ptr on the HEAP, we need to delete it or we'll have a memory leak
	Person* personPtr = new Person("Lacy");
	personPtr->printName();

	delete personPtr;

	Person* tmp = getPerson();
}

Person* getPerson()
{
	return new Person("Cosmo");
}

void customSmartPtr()
{
	SmartPersonPointer smartPerson(new Person("Cosmo"));
	smartPerson->printName();
	(*smartPerson).printName();

	//SmartPersonPointer badPtr(new int(23));

	SmartPointer<Person> ex1(new Person("Moxie"));
	SmartPointer<int> ex2(new int(32));

//	SmartPointer<Person> ex1Copy = ex1; // won't work yet!
}
