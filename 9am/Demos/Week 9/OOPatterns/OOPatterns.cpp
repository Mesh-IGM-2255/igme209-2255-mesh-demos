// OOPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#include <iostream>
using namespace std;

#include "Singleton.h"
#include "Observer.h"
#include "Subject.h"
#include "Log.h"

void singletonDemo();
void observerDemo();

int main()
{
    singletonDemo();
    observerDemo();

    if (_CrtDumpMemoryLeaks())
        cout << "\nPossible memory leaks" << endl;
    else
        cout << "\nNo memory leaks. :)" << endl;
}

void singletonDemo()
{
    //Singleton myInstance;

    for (int i = 0; i < 10; i++)
    {
        Singleton* sharedInst = Singleton::getInstance();
        sharedInst->instanceInfo();
    }
}

void observerDemo()
{
    Observer pax("Pax");
    Observer shiro("Shiro");
    Observer lacy("Lacy");
    Log msglog;

    Subject family;
    family.registerObserver(&pax);
    family.registerObserver(&shiro);
    family.registerObserver(&lacy);
    family.registerObserver(&msglog);

    family.eventObserved("Dinner time!");
    cout << endl;

    family.eventObserved("Who knocked that over?!");
    cout << endl;

    family.eventObserved("Bed time!");
    cout << endl;

    msglog.printLog();
}