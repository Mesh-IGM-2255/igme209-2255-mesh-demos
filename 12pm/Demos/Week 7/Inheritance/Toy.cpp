#include "Toy.h"

using namespace std;
#include <iostream>

Toy::Toy()
	: Toy("Rock", 0.0f)
{

}

Toy::Toy(string _name, float _price)
{
	name = _name;
	price = _price;
}


void Toy::Print()
{
	cout << "Toy name: " << name << endl;
}