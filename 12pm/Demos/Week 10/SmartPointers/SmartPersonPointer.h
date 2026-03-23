#pragma once

#include "Person.h"

// BARE BONES -- **NOT** a full smart pointer!!

class SmartPersonPointer
{
public:
	SmartPersonPointer(Person* _ptr = nullptr);
	~SmartPersonPointer();

	// We're going to create instances of this on the STACK, but we want
	// to use it like it's a ptr. Overloading the * and -> operators
	// let's us pass along the dereference and member access operators
	// to the underlying ptr.
	Person& operator *();
	Person* operator ->();

private:
	Person* ptr;
	// static int refCount; // eventually need this. can't without rule of three
};

