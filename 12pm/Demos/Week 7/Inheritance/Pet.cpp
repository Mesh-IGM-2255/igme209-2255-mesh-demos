#include "Pet.h"

#include <iostream>
using namespace std;

Pet::Pet(string _name, string _sound)
{
	cout << "+Pet" << endl;
	name = _name;
	sound = _sound;
}

void Pet::talk()
{
	cout << "P - ";
	cout << name << " " << sound << endl;
}
