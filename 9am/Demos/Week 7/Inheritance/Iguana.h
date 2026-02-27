#pragma once

#include "Pet.h"

class Iguana : 
	public Pet
{
public:
	Iguana(std::string _name, unsigned short _age);
	~Iguana();
	void print() override;

private:
	double warmth;
};

