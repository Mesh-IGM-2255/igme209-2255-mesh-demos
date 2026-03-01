#include "Cleric.h"
#include <iostream>
using namespace std;


Cleric::Cleric() : Cleric("Cleric", "Binky")
{
	#ifdef CHAR_DEBUG_ON 
	cout << "+Cleric" << endl;
	#endif
}

Cleric::Cleric(std::string _name, std::string _deity)
	: Character(_name)
{
	#ifdef CHAR_DEBUG_ON 
	cout << "+Cleric(" << _name << ")" << endl;
	#endif
	deity = _deity;
	childDynamicData = new int(24);
}

Cleric::~Cleric()
{
#ifdef CHAR_DEBUG_ON 
	cout << "~Cleric(" << name << ")" << endl;
#endif
	delete childDynamicData;
}


void Cleric::PrintData()
{
	Character::PrintData();
	cout << "\tBelieves In: " << deity << " (" << *childDynamicData << ")" << endl;
}


void Cleric::PrintType()
{
	cout << "\tType: Cleric!" << endl;
}
