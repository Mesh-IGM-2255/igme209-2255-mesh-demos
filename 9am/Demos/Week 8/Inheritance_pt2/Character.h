#pragma once

// Using string so we don't have to worry about memeory management
#include <string>

#define CHAR_DEBUG_ON 1

struct Character
{

public:
	Character();
	Character(std::string _name);

	virtual ~Character();

	virtual void PrintData();

	virtual void PrintType();

protected:
	std::string name;

private:
	int* parentDynamicData;
};
