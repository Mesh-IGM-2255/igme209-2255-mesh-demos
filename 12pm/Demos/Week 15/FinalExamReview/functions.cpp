#include "functions.h"
#include <iostream>
#include <vector>
#include <thread>

using namespace std;

#include "Stuff.h"

void example1()
{
	cout << "\n~~~ Test Set 1 ~~~" << endl;
	// TODO: Uncomment when ready to test
	/*
	int a = 3;
	int b = 4;
	int c = a + b;
	cout << "The sum of " << a << " and " << b << " is: " << c << endl;
	*/
}

void example2()
{
	cout << "\n~~~ Test Set 2 ~~~" << endl;
	// TODO: you'll have to add code here to test other things
}

void testTemplate()
{
	Stuff<int> aInt(1);
	Stuff<float> aFloat(1.5f);

	Stuff<int>* aIntPtr = new Stuff<int>(aInt);
	delete aIntPtr;

	Stuff<int> b(3);
	b = aInt;
	b = b;


	int thing = 23;
	int* ptr = &thing;
}
