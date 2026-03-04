#include "Multiclass.h"

#include <iostream>
using namespace std;

Multiclass::Multiclass()
	: Multiclass("Multiclass", 0, "None")
{
#ifdef CHAR_DEBUG_ON 
	cout << "+Multiclass" << endl;
#endif
}

Multiclass::Multiclass(std::string _name, int _numSpells, std::string _deity)
	: Character(_name), Sorcerer(_name, _numSpells), Cleric(_name, _deity)
{
#ifdef CHAR_DEBUG_ON 
	cout << "+Multiclass(" << _name << ")" << endl;
#endif
}

Multiclass::~Multiclass()
{
#ifdef CHAR_DEBUG_ON 
	cout << "~Multiclass(" << name << ")" << endl;
#endif
}

void Multiclass::PrintData()
{
	Cleric::PrintData();
	cout << "\tHas " << numSpells << " spells." << endl;
}

void Multiclass::PrintType()
{
	cout << "\tType: Multiclass!" << endl;
}
