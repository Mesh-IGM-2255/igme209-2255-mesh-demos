// SmartPointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

using namespace std;

#include "Person.h"
#include "SmartPersonPointer.h"
#include "SmartPtr.h"

void ptrReview();
Person* createPerson(string name);
void smartPerson();

int main()
{
	//ptrReview();
	smartPerson();

	if (_CrtDumpMemoryLeaks())
		std::cout << "\nMemory leaks?!" << std::endl;
	else
		std::cout << "\nNo leaks :)" << std::endl;
}

void ptrReview()
{
	// If we create a default person on the STACK, not a big deal. 
	// It'll go away when the function ends
	Person person("Shiro");
	person.printName();

	// If we make the ptr on the HEAP, we need to delete it or we'll have a memory leak
	Person* personPtr = new Person("Lacy");
	personPtr->printName();

	delete personPtr;

	//Person* tmp = createPerson("Pax");
}

Person* createPerson(string name)
{
	return new Person(name);
}

void smartPerson()
{
	SmartPersonPointer smartPerson(new Person("Cosmo"));
	smartPerson->printName();

	//SmartPersonPointer badSmartptr(new std::string());

	SmartPtr<Person> ex1(new Person("Moxie"));
	SmartPtr<int> ex2(new int(12));
}