#pragma once

#include <string>

class Observer
{
public:
	Observer(std::string _name);
	virtual void notify(std::string msg);

private:
	std::string name;
};

