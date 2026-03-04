#pragma once

#include "Sorcerer.h"
#include "Cleric.h"

class Multiclass
	: public Cleric, public Sorcerer
{
public:
	Multiclass();
	Multiclass(std::string _name, int _numSpells, std::string _deity);
	~Multiclass();

	void PrintData() /*const*/ override;
	void PrintType() /*const*/ /* override */;
};

