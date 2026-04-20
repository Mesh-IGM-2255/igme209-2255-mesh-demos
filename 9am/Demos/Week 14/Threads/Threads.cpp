// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include "FibCalc.h"

using namespace std;

void printHello()
{
    cout << "Hello" << endl;
}

void printGoodbye(int num)
{
    cout << "Goodbye! ";
    this_thread::sleep_for(2s);
    cout << num << endl;
}

void printInfo(int info, mutex* mtx)
{
    mtx->lock();

    cout << "Thread # " << info << " is running " << endl;

    mtx->unlock();
}

int main()
{
    /*
    printHello();
    printGoodbye(42);
    */

    // create a new thread
    // thread threadName(functionName, functParams);

    /*
    thread goodbyeThread(printGoodbye, 13);
    thread helloThread(printHello);

    helloThread.join();
    cout << "Hello done" << endl;

    goodbyeThread.join();
    cout << "Goodbye done" << endl;
    */

    FibCalc fib = FibCalc();
    /*
    fib.PrintFibNum(5);
    for (int i = 0; i <= 45; i++)
    {
        fib.PrintFibNum(i);
    }
    */

    vector<thread*> threads;

    /*
    for (int i = 0; i <= 45; i++)
    {
        threads.push_back(new thread(&FibCalc::PrintFibNum, fib, i));
        // do NOT join here
    }

    for (int i = 0; i < threads.size(); i++)
    {
        threads[i]->join();
        delete threads[i];
    }
    */

    mutex coutMtx;
    /*
    threads.clear();
    for (int i = 0; i <= 10; i++)
    {
        threads.push_back(new thread(printInfo, i, &coutMtx));
        // do NOT join here
    }

    for (int i = 0; i < threads.size(); i++)
    {
        threads[i]->join();
        delete threads[i];
    }
    */

    threads.clear();
    for (int i = 45; i >= 0; i--)
    {
        threads.push_back(new thread(&FibCalc::PrintFibNumMtx, fib, i, &coutMtx));
        // do NOT join here
    }

    for (int i = 0; i < threads.size(); i++)
    {
        threads[i]->join();
        delete threads[i];
    }

}
