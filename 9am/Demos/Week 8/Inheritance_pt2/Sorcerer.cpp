#include "Sorcerer.h"

#include <iostream>
using namespace std;


Sorcerer::Sorcerer() : Sorcerer("Sorcerer", 1)
{
#ifdef CHAR_DEBUG_ON 
	cout << "+Sorcerer" << endl;
#endif
}

Sorcerer::Sorcerer(std::string _name, int _numSpells)
	: Character(_name)
{
#ifdef CHAR_DEBUG_ON 
	cout << "+Sorcerer(" << _name << ")" << endl;
#endif
	numSpells = _numSpells;
}

Sorcerer::~Sorcerer()
{
#ifdef CHAR_DEBUG_ON 
	cout << "~Sorcerer(" << name << ")" << endl;
#endif
}


void Sorcerer::PrintData()
{
	Character::PrintData();
	cout << "\tHas " << numSpells << " spells." << endl;
}


void Sorcerer::PrintType()
{
	cout << "\tType: Sorcerer!" << endl;
}
