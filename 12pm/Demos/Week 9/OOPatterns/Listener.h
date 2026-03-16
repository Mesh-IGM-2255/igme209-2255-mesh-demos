#pragma once

#include <string>

class Listener
{
public:
	Listener(std::string _name);
	virtual void notify(std::string msg);

private:
	std::string name;
};

