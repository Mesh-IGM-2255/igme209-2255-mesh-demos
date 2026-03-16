#pragma once

#include <vector>
#include "Observer.h"

class Subject
{
public:
	void registerObserver(Observer* _obs);
	void clearObservers();
	void eventObserved(std::string event);

private:
	std::vector<Observer*> observers;

};

