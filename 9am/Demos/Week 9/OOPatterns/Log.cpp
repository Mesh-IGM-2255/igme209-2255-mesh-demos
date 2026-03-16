#include "Log.h"

#include <iostream>
using namespace std;

Log::Log()
	: Observer("Log")
{
}

void Log::notify(std::string _msg)
{
	Observer::notify(_msg);
	msgs.push_back(_msg);
}

void Log::printLog()
{
	for (int i = 0; i < msgs.size(); i++)
	{
		cout << "Msg " << (i + 1) << ": " << msgs[i] << endl;
	}
}
