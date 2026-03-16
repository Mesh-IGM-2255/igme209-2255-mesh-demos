#include "Observer.h"

#include <iostream>
using namespace std;

Observer::Observer(std::string _name)
{
	name = _name;
}

void Observer::notify(std::string _msg)
{
	cout << "[" << name << "] Msg rcvd: " << _msg << endl;
}
