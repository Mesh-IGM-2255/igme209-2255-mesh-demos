#pragma once

#include <vector>
#include "Listener.h"

class Observer
{
public:
	void registerListener(Listener* _obs);
	void clearListeners();
	void eventObserved(std::string event);

private:
	std::vector<Listener*> listeners;

};

