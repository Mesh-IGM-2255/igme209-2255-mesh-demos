// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printSize(int data[]);
void printData(int data[], const unsigned SIZE);

int main()
{
	/*
	* [  |  |  ]
	* C# -- int[] nums;
	*		nums = new int[3];
	*/

	int defaultNums[5];
	cout << defaultNums[4] << endl;

	int allZeroes[5] = {};
	int initData[5] = { 1, 2, 3, 4, 5 };
	int partialInit[5] = { 1, 2 };

	for (int i = 0; i < 5 ; i++)
	{
		cout << initData[i] << endl;
	}


	const unsigned int SIZE = 10;
	int data[SIZE] = {};
	data[SIZE - 1] = 42;

	cout << "sizeof(data):" << sizeof(data) << endl;
	cout << "len = sizeof(data)/sizeof(int):" << sizeof(data)/ sizeof(int) << endl;

	printSize(data);
	printData(data, SIZE);
}

void printSize(int data[])
{
	cout << "ps: sizeof(data):" << sizeof(data) << endl;
	cout << "ps: len = sizeof(data)/sizeof(int):" << sizeof(data) / sizeof(int) << endl;
}

void printData(int data[], const unsigned SIZE)
{
	data[1] = 10; // modifying here modifies the underlying array

	// Loops work as expected
	for (unsigned int i = 0; i < SIZE; i++)
	{
		cout << data[i] << ", ";
	}
	cout << endl;
}