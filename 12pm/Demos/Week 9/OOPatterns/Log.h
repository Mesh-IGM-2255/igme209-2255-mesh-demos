#pragma once

#include "Observer.h"
#include <vector>

class Log : public Observer
{
public:
	Log();
	void notify(std::string _msg) override;
	void printLog();

private:
	std::vector<std::string> msgs;
};

