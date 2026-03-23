#pragma once

#include <typeinfo>
#include <iostream>

// Check the "inline" box when making the class so that everything
// is in the header file and not in a separate .cpp file

// Need in the H so a version for each different type of T is created

template <class T>
class TemplateEx
{
public:
	TemplateEx(T value)
	{
		data = value;
		std::cout << "At runtime, 'T' is of type ";
		std::cout << typeid(data).name() << std::endl << std::endl;
	}

private:
	T data;
};

