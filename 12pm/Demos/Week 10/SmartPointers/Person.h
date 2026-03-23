#pragma once

#include <string>
class Person
{
public:
	Person(std::string _name);
	~Person(); // don't actually need one, but we want to see if it gets called

	void printName();

private:
	std::string name;
};


