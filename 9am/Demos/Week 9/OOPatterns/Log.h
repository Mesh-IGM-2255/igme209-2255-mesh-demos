#pragma once

#include "Listener.h"
#include <vector>

class Log : public Listener
{
public:
	Log();
	void notify(std::string _msg) override;
	void printLog();

private:
	std::vector<std::string> msgs;
};

