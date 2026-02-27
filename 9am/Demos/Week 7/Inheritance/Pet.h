#pragma once

#include <string>
#include <vector>
#include "Toy.h"

class Pet
{
public:
	Pet(std::string _name, unsigned short _age);
	~Pet();
	virtual void print();

	int publicField;

protected:
	int protectedField;
	std::vector<Toy*> toys;

private:
	int privateField;
	std::string name;
	unsigned short age;
};

