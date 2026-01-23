// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printSize(int data[]);
void printData(int data[], const unsigned SIZE);

int main()
{
	// C#: -- int[] nums = new int[5];

	// creation & init
	int defaultNums[5];
	cout << "defaultNums[4]:" << defaultNums[4] << endl;

	int allZeroes[5] = {};
	int nums[5] = { 1, 2, 3, 4, 5 };
	int partialInit[5] = { 1,2 };


	// length
	const unsigned int MY_DATA_SIZE = 5;
	int data[MY_DATA_SIZE] = {};
	data[MY_DATA_SIZE - 1] = 123;

	cout << "Last: " << data[MY_DATA_SIZE - 1] << endl;
	cout << "MY_DATA_SIZE: " << MY_DATA_SIZE << endl;
	cout << "sizeof(data): " << sizeof(data) << endl;
	cout << "length = sizeof(data)/sizeof(int): " << sizeof(data) / sizeof(int) << endl << endl;

	printSize(data);
	printData(data, MY_DATA_SIZE);

}


void printSize(int data[])
{
	cout << "ps: sizeof(data): " << sizeof(data) << endl;
	cout << "ps: length = sizeof(data)/sizeof(int): " << sizeof(data) / sizeof(int) << endl;
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
