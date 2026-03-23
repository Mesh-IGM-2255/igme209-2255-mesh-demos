#pragma once

#include "Person.h"

class SmartPersonPointer
{
public:
	SmartPersonPointer(Person* _ptr = nullptr);
	~SmartPersonPointer();

	// We're going to create instances of this on the stack, but we want
	// to use it like it's a ptr. Overloading the * and -> operators
	// let's us pass along the dereference and member access operators
	// to the underlying ptr.
	Person& operator *();
	Person* operator ->();

	// Our smart pointer class is now effectively a wrapper/proxy to
	// and underlying ptr


private:
	Person* ptr;
};

