#include "otherFile.h"

#include <iostream>
using namespace std;

void thing()
{
	cout << "HELLO!" << endl;
}

int addNumbers(int a, int b)
{
	return a + b;
}

int multiplyNumbers(int a, int b)
{
	return a * b;
}

void runTwoNumsFunction(twoNumsFuncType funcPtr, int a, int b)
{
	cout << funcPtr(a, b) << endl;
}