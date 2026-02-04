// PointerUsage.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	// create an int var with data on the stack
	int num = 42;

	// pointer variable to that int data on the stack
	int* numPtr = &num; // initialize to address of the data in num variable

	// delete numPtr; // BAD - don't delete on the stack
	num = 0;
	numPtr = nullptr; // ok

	// new ptr variable to new int data on the heap
	int* otherPtr = new int(12); // initialize to addr of new data on the HEAP

	delete otherPtr; // without this -- memory leak
	otherPtr = nullptr; // without this -- dangling pointer

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// all of the stack for simplicity

	int myArray[3] = { 1, 2, 3 };
	cout << myArray << ": " << myArray[0] << endl;

	int* arr0 = myArray;
	cout << arr0 << ": " << *arr0 << endl;

	int* arr1 = arr0 + 1;  // 1 == 1 * sizeof(int)
	//&myArray[1]; 
	cout << arr1 << ": " << *arr1 << endl;

	int* arr2 = arr0 + 2;
	cout << arr2 << ": " << *arr2 << endl << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << (myArray + i) << ": " << myArray[i] << endl;
	}
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		int* currPtr = myArray + i;
		cout << currPtr << ": " << *currPtr << endl;
	}
	cout << endl;

	for (int* currPtr = myArray;  currPtr < myArray + 3  ;currPtr++)
	{
		cout << currPtr << ": " << *currPtr << endl;
	}
	cout << endl;


	char name[6] = "Shiro";
	char* letter = name;
	while (*letter != '\0')
	{
		cout << *letter;
		letter++;
	}
	cout << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	// Not allowed for HW1!

	string myString = "Hello"; // on the stack!
	cout << myString << endl;

	myString.pop_back(); // remove last letter
	cout << myString << endl;

	string* myStrPtr = &myString;
	// myStrPtr.pop_back();
	(*myStrPtr).pop_back();
	myStrPtr->pop_back();

}

/*
void printString(char* word)
{

}
*/
