#include "Character.h"
#include <iostream>
using namespace std;


Character::Character() : Character("Character")
{
	#ifdef CHAR_DEBUG_ON 
	cout << "+Character" << endl;
	#endif
}

Character::Character(std::string _name)
{
	#ifdef CHAR_DEBUG_ON 
	cout << "+Character(" << _name << ")" << endl;
	#endif

	name = _name;
	parentDynamicData = new int(12);
}

Character::~Character()
{
	#ifdef CHAR_DEBUG_ON 
	cout << "~Character(" << name << ")" << endl;
	#endif
	delete parentDynamicData;
}

void Character::PrintData()
{
	cout << name << " (" << *parentDynamicData << ")" << endl;
}

void Character::PrintType()
{
	cout << "\tType: Character!" << endl;
}
