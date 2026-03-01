#pragma once

#include "Character.h"

class Cleric :
	public Character
{
public:
	Cleric();
	Cleric(std::string _name, std::string _deity);
	~Cleric();	

	void PrintData();
	void PrintType();

protected:
	std::string deity;

private:
	int* childDynamicData;
};
