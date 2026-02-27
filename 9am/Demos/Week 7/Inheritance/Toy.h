#pragma once

#include <string>

struct Toy
{
public:
	Toy();
	Toy(std::string _name, float _price);
	void Print();

private:
	std::string name;
	float price;
};