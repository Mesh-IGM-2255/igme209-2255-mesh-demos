// PointerUsage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	// create an int on the stack
	int num = 42;

	// pointer to that int
	int* numPtr = &num; // create a variable, numPtr that holds an addr to an int
						// intialize that to be the addr of where the data for num is

	// new pointer variable to new int data on the heap
	int* numPtrHeap = new int(12);

	// need to delete!!
	delete numPtrHeap;
	numPtrHeap = nullptr;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// all on the stack for simplicity

	int myArray[3] = { 1, 2, 3 };
	int* arr0 = myArray;
	cout << arr0 << endl;

	arr0 = &myArray[0];
	cout << arr0 << endl;
	cout << *arr0 << endl << endl;

	int* arr1 = &myArray[1];
	cout << arr1 << endl;

	arr1 = myArray + 1; // 1 -- units == ? == 1 * sizeof(int)
	cout << arr1 << endl;
	cout << *arr1 << endl << endl;

	int* arr2 = myArray + 2;
	cout << arr2 << endl;
	cout << *arr2 << endl << endl;

	int* currentElement = myArray;
	for (int i = 0; i < 3; i++)
	{
		currentElement = myArray + i;
		cout << i << " - "<< currentElement << ": " << *currentElement << endl;
	}

	for (int* curr = myArray; curr < myArray + 3; curr++)
	{
		cout << curr << ": " << *curr << endl;
	}

	char name[6] = "Shiro";
	cout << name << endl;

	char* currLet = name;
	while (*currLet != '\0')
	{
		cout << *currLet;
		currLet++;
	}
	cout << endl;


	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// NOT ALLOWED for HW1!!

	string myString = "Hello";
	cout << myString << endl;
	myString.pop_back();
	cout << myString << endl;

	string* myStrPtr = &myString;
	//myStrPtr.pop_back();
	(*myStrPtr).pop_back();
	myStrPtr->pop_back();
}
