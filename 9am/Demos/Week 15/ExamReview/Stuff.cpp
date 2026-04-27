#include "Stuff.h"

Stuff::Stuff()
{
	thing1 = 1;
	thing2 = 2;
	thingPtr = new int(42);
}

Stuff::~Stuff()
{
	delete thingPtr;
}

Stuff::Stuff(Stuff& other)
{
	this->thing1 = other.thing1;
	this->thing2 = other.thing2;

	// NO -- shallow
	//this->thingPtr = other.thingPtr;

	this->thingPtr = new int(*(other.thingPtr));
}

Stuff& Stuff::operator=(Stuff& other)
{
	if (&other == this)
	{
		return *this;
	}

	// clean up existing mem
	delete thingPtr;

	// then deep copy
	this->thing1 = other.thing1;
	this->thing2 = other.thing2;
	this->thingPtr = new int(*(other.thingPtr));

	return *this;
}
