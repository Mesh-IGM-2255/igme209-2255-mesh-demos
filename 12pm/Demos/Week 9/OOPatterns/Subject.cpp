#include "Subject.h"

void Subject::registerObserver(Observer* _obsPtr)
{
	observers.push_back(_obsPtr);
}

void Subject::clearObservers()
{
	observers.clear();
}

void Subject::eventObserved(std::string event)
{
	for (int i = 0; i < observers.size(); i++)
	{
		observers[i]->notify(event);
	}
}
