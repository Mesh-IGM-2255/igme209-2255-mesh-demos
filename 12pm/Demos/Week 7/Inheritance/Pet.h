#pragma once

#include <string>

class Pet
{
public:
	Pet(std::string _name, std::string _sound);
	virtual void talk();
	int publicField;

protected:
	int protectedField;

private:
	int privateField;
	std::string name;
	std::string sound;
};

