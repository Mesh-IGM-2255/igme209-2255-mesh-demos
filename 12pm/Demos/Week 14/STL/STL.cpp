// STL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// STL isn't on the exam, but important to be familiar with for any future work in C++
// LOTS of common data containers, but also algorithms for those containers

#include <iostream>
#include <time.h>
#include <algorithm> // STL algorithms (sort, search, etc.)

// each data structure is in its own include
#include <vector> // we've already used this
#include <array>
#include <list>
#include <map>
// etc etc


void printArray(const char* label, int* arr, const unsigned int SIZE);

int main()
{
	srand(time(NULL));

	const unsigned int SIZE = 10;
	int nums[SIZE];
	for (unsigned int i = 0; i < SIZE; i++)
	{
		nums[i] = rand() % 100;
	}


	printArray("Starting array", nums, SIZE);
	std::sort(nums, nums + SIZE); // ptr to start of the array and ptr to the end 
	printArray("Sorted array", nums, SIZE);

	// Can also pass in a lambda function to define the comparison behavior for the sort
	std::sort(nums, nums + SIZE, [](int a, int b) { return a > b; }); // sort in descending order
	printArray("Sorted array (descending)", nums, SIZE);

	// Use binary search to find a number in the array -- requires an ascending sort
	nums[5] = 42;	// Cheat and put 42 in our array
	std::sort(nums, nums + SIZE);
	printArray("\nBefore search", nums, SIZE);
	bool exists = std::binary_search(nums, nums + SIZE, 42);
	if (exists)
	{
		std::cout << "Found it!" << std::endl;
	}
	else
	{
		std::cout << ":(" << std::endl;
	}

	// Most of the algorithms will work on almost any data structure
	bool allEven = std::all_of(nums, nums + SIZE, [](int n) { return n % 2 == 0; });
	if (allEven)
	{
		std::cout << "All even!" << std::endl;
	}
	else
	{
		std::cout << "Not all even!" << std::endl;
	}

	// std::array - template class for a fixed-size array of a certain type
	std::array<int, SIZE> arr;
	std::sort(arr.begin(), arr.end()); // begin() and end() return iterators, not ptrs
	printArray("sorted array", &arr.front(), arr.size());

	// std::map - associative array (key-value pairs)
	std::map<std::string, int> empIDs;
	empIDs["Shiro"] = 1234;
	empIDs["Pax"] = 5678;
	empIDs["Binky"] = 0;
}

void printArray(const char* label, int* arr, const unsigned int SIZE)
{
	std::cout << label << ": ";
	for (unsigned int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


