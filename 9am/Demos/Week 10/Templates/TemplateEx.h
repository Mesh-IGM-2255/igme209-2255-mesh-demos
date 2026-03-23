#pragma once

#include <typeinfo>
#include <iostream>

template <class T>
class TemplateEx
{
public:
	TemplateEx(T _initValue)
	{
		myVar = _initValue;
		std::cout << "At runtime, 'T' is of type ";
		std::cout << typeid(myVar).name() << std::endl << std::endl;
	}

private:
	T myVar;
};

