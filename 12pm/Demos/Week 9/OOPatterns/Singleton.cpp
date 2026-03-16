#include "Singleton.h"

#include <iostream>
using namespace std;

Singleton* Singleton::getInstance()
{
	static Singleton instance;
	instance.instanceGets++;
	return &instance;
}

void Singleton::instanceInfo()
{
	cout << "Instance gets: " << instanceGets << endl;
}

Singleton::Singleton()
{
	cout << "+Singleton()" << endl;
}

Singleton::~Singleton()
{
	cout << "~Singleton()" << endl;
}
