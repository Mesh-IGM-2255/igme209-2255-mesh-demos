#pragma once

#include "Character.h"

// OVERRIDE == Call this INSTEAD of the parent one!
// Technically optional, but really good idea since it'll catch method
// signature mismatches
// 
// In older versions of C++ it meant "call INSTEAD" -- which would
// be a bad idea for destructors
// https://learn.microsoft.com/en-us/cpp/cpp/override-specifier?view=msvc-170

class Cleric :
	public Character
{
public:
	Cleric();
	Cleric(std::string _name, std::string _deity);
	~Cleric();	// NEVER OVERRIDE

	void PrintData() /*const*/ override;
	void PrintType() /*const*/ /* override */;

protected:
	std::string deity;

private:
	int* childDynamicData;
};
