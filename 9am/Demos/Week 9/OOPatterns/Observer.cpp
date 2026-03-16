#include "Observer.h"

void Observer::registerListener(Listener* _lisPtr)
{
	listeners.push_back(_lisPtr);
}

void Observer::clearListeners()
{
	listeners.clear();
}

void Observer::eventObserved(std::string event)
{
	for (int i = 0; i < listeners.size(); i++)
	{
		listeners[i]->notify(event);
	}
}
