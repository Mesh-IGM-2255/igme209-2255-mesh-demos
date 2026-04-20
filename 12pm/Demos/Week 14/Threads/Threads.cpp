// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

#include "FibCalc.h"

using namespace std;

void printHello() {
	cout << "Hello!" << endl;
}

void printGoodbye(int num) {
	cout << "Goodbye! ";
	this_thread::sleep_for(2s);
	cout << num << endl;
}

void printInfo(int info, mutex* mtx)
{
	mtx->lock();
	cout << "Thread #" << info << " is running!" << endl;
	mtx->unlock();
}

int main()
{
	/*
	//printHello();
	//printGoodbye(42);

	// thread threadName(functionName, params)
	thread helloThread(printHello);
	thread goodbyeThread(printGoodbye, 12);
	cout << "It's Monday" << endl;

	helloThread.join();
	goodbyeThread.join();
	cout << "All done!" << endl;
	*/

	/*
	vector<thread*> threads;
	mutex mtx;
	for (int i = 0; i < 10; i++)
	{
		threads.push_back(new thread(printInfo, i, &mtx));
		// do NOT join here
	}

	for (int i = 0; i < threads.size(); i++)
	{
		threads[i]->join();
		delete threads[i];
	}
	threads.clear();
	*/

	FibCalc fib;
	/*
	for (int i = 0; i <= 30; i++)
	{
		fib.PrintFibNum(i);
	}
	*/
	vector<thread*> fibThreads;
	mutex cMutex;
	for (int i = 45; i >= 0; i--)
	{
		fibThreads.push_back(new thread(&FibCalc::PrintFibNumMtx, fib, i, &cMutex));
	}

	for (int i= 0; i < fibThreads.size(); i++)
	{
		fibThreads[i]->join();
		delete fibThreads[i];
	}
	fibThreads.clear();


}
