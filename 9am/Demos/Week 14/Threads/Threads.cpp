// Threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <future>
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

void testFuture(promise<unsigned int>* promiseObj)
{
    FibCalc fib = FibCalc();
    cout << "Starting calc" << endl;
    unsigned int val = fib.CalcFibNum(45);

    promiseObj->set_value(val);

    cout << "Finished calc" << endl;
}

int main()
{
    /*
    printHello();
    printGoodbye(42);

    // create a new thread
    // thread threadName(functionName, functParams);

    thread goodbyeThread(printGoodbye, 13);
    thread helloThread(printHello);

    helloThread.join();
    cout << "Hello done" << endl;

    goodbyeThread.join();
    cout << "Goodbye done" << endl;

    FibCalc fib = FibCalc();
    fib.PrintFibNum(5);
    for (int i = 0; i <= 45; i++)
    {
        fib.PrintFibNum(i);
    }

    vector<thread*> threads;

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

    mutex coutMtx;

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
*/

    /*
    // contract
    promise<unsigned int> promiseObj;

    // waits for the promise
    future<unsigned int> futureInt = promiseObj.get_future();

    // make a thread tied to the promise
    thread bgThread = thread(testFuture, &promiseObj);

    // do whatever while we wait
    cout << "game loop" << endl;
    while (true)
    {
        cout << ".";
        if (futureInt._Is_ready()) // _ == non std
        {
            cout << "Fib calc promise done: " << futureInt.get() << endl;
            break;
        }
    }
    bgThread.join();
    */

    // auto == a type that is determined at compile time
    // auto varName = [capture clause](parameters) -> returnType { function body }
    int y = 5;
    auto myLambda = [&y](float x)
        {
            cout << "x = " << x << endl;
            cout << "y = " << y << endl;
            y++;
        };

    myLambda(5.0f);
    cout << "y is now " << y << endl;

    auto threadLambda = [](int num) { cout << "Thread is running! " << num << endl; };
    thread lambdaThread(threadLambda, 10);
    lambdaThread.join();

    thread lambdaThread2(
        [](int num) {cout << "Thread lambda 2 is running! " << num << endl; },
        15
    );
    lambdaThread2.join();
}
