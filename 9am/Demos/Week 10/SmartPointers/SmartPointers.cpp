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

#include <memory>
void uniquePtr();
void sharedPtr();
void gotchas();

int main()
{
	//ptrReview();
	//smartPerson();
	//uniquePtr();
	//sharedPtr();
	gotchas();

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
	//SmartPtr<Person> copy = ex1; // BAD
	SmartPtr<int> ex2(new int(12));
}
void uniquePtr()
{
	std::unique_ptr<Person> uniquePerson(new Person("Aiden"));

	// NOT ALLOWED
	// std::unique_ptr<Person> copyUPtr = uniquePerson;

	std::unique_ptr<Person> newOwner = std::move(uniquePerson);
}

void sharedPtr()
{
	// Shared goverance
	std::shared_ptr<Person> owner1(new Person("Aiden"));
	std::shared_ptr<Person> owner2(owner1); // use copy constructor
	std::shared_ptr<Person> owner3 = owner2; // using assignment to copy
}

void gotchas()
{
	Person* extraPerson = new Person("Extra");

	// ONLY HAVE ONE OWNER!
	std::unique_ptr<Person> uniqPerson(extraPerson);
	std::shared_ptr<Person> sharedPerson(extraPerson);
	std::shared_ptr<Person> sharedPerson2(extraPerson);
}