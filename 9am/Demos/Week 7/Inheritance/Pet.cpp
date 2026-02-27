#include "Pet.h"

#include <iostream>
using namespace std;

Pet::Pet(string _name, unsigned short _age)
{
	cout << "+Pet" << endl;
	name = _name;
	age = _age;
	for (short i = 0; i < 1; i++)
	{
		toys.push_back(new Toy()); // Add
	}
}

Pet::~Pet()
{
	for (short i = 0; i < toys.size(); i++)
	{
		delete toys[i];
	}
}

void Pet::print()
{
	cout << name << " is " << age << " and has " << toys.size() << " toys:" << endl;
	for (short i = 0; i < toys.size(); i++)
	{
		toys[i]->Print(); // Can still access like an array
	}
}
