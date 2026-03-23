#include "SmartPersonPointer.h"

SmartPersonPointer::SmartPersonPointer(Person* _ptr)
{
	ptr = _ptr;
}

SmartPersonPointer::~SmartPersonPointer()
{
	delete ptr;
}

Person& SmartPersonPointer::operator*()
{
	return *ptr;
}

Person* SmartPersonPointer::operator->()
{
	return ptr;
}
