#include "Dog.h"

#include <iostream>
using namespace std;

Dog::Dog(std::string _name)
	: Pet(_name, "barks")
{
	cout << "+Dog" << endl;
	volume = 1;
}

void Dog::talk()
{
	cout << "D - ";
	for (int i = 0; i < volume; i++)
	{
		Pet::talk();
	}
	volume++;
}

