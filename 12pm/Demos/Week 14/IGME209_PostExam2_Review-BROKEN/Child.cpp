#include "Child.h"
#include <iostream>

// TODO: Make this compile
Child::Child(std::string name)
{
	std::cout << "Child()"<< std::endl;
	moreData = new int[MORE_DATA_SIZE];
	for (int i = 0; i < MORE_DATA_SIZE; i++)
	{
		moreData[i] = rand() % 10;
	}
}

void Child::Display()
{
	// TODO: Make sure the Parent's data is displayed first
	std::cout << "\tDataSet2: ";
	for (int i = 0; i < MORE_DATA_SIZE; i++)
	{
		std::cout << moreData[i] << " ";
	}
	std::cout << std::endl;
}
