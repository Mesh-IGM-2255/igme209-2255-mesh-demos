#include "Log.h"

#include <iostream>
using namespace std;

Log::Log()
	: Listener("Log")
{
}

void Log::notify(std::string _msg)
{
	Listener::notify(_msg);
	msgs.push_back(_msg);
}

void Log::printLog()
{
	for (int i = 0; i < msgs.size(); i++)
	{
		cout << "Msg " << (i + 1) << ": " << msgs[i] << endl;
	}
}
