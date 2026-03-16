#include "Listener.h"

#include <iostream>
using namespace std;

Listener::Listener(std::string _name)
{
	name = _name;
}

void Listener::notify(std::string _msg)
{
	cout << "[" << name << "] Msg rcvd: " << _msg << endl;
}
