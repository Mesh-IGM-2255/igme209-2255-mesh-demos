#include "Iguana.h"

#include <iostream>
using namespace std;

Iguana::Iguana(std::string _name, unsigned short _age)
	: Pet(_name, _age)
{
	cout << "+Iguana" << endl;
	warmth = 1.0;
}

Iguana::~Iguana()
{
}

void Iguana::print()
{
	// cout << name <<
	Pet::print();
	cout << " and is " << (warmth * 100) << "% warm" << endl;
	warmth *= 0.9;
}
