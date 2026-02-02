#include "functions.h"

#include <iostream>
using namespace std;

void passByValue(int a)
{
	a += 5;
	cout << "- by value + 5: " << a << endl;
}

void passByPtr(int* a)
{
	*a += 5;
	cout << "- by ptr + 5: " << *a << endl;
}

void passByReference(int& a)
{
	a += 5;
	cout << "- by ref + 5: " << a << endl;
}

