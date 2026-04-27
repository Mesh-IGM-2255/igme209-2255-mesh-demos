#include "functions.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

#include "Stuff.h"

void example1()
{
	cout << "\n~~~ Test Set 1 ~~~" << endl;
	// TODO: Uncomment when ready to test
	/*
	int a = 3;
	int b = 4;
	int c = a + b;
	cout << "The sum of " << a << " and " << b << " is: " << c << endl;
	*/
}

void example2()
{
	cout << "\n~~~ Test Set 2 ~~~" << endl;
	// TODO: you'll have to add code here to test other things
}

void testStuff()
{
	Stuff a;
	Stuff* b = new Stuff(a);
	delete b;

	Stuff c;
	c = a;
	c = c;

	/*
	print(5);
	print(10);
	print(15);
	*/

	mutex mtx;

	thread t1(print, 5, &mtx);
	thread t2(print, 10, &mtx);
	thread t3(print, 15, &mtx);

	t1.join();
	t2.join();
	t3.join();
}

void print(int num, mutex* mtx)
{
	mtx->lock();
	for (int i = 0; i < num; i++)
	{
		cout << num << "-";
	}
	mtx->unlock();
}
