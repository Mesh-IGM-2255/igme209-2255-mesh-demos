#pragma once
#include "Character.h"

class Sorcerer :
    virtual public Character
{
public:
	Sorcerer();
	Sorcerer(std::string _name, int _numSpells);

	// Technically don't need this
	~Sorcerer();	 // DO NOT OVERRIDE EVER - esp pre C++11

	void PrintData() /*const*/ /*override*/;
	void PrintType() /*const*/ override;

protected:
    int numSpells;

};

