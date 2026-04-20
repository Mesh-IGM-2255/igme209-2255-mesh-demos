#include "FibCalc.h"

#include <iostream>
using namespace std;

void FibCalc::PrintFibNum(int num)
{
	cout << num << " = " << CalcFibNum(num) << endl;;
}

void FibCalc::PrintFibNumMtx(int num, std::mutex* mtx)
{
	int fibNum = CalcFibNum(num);

	mtx->lock();
	cout << num << " = " << fibNum << endl;
	mtx->unlock();
}

// Intentionally using the inefficient recursive method to calculate 
// Fibonacci numbers
unsigned int FibCalc::CalcFibNum(int num)
{
	if (num <= 2)
	{
		return 1;
	}
	return CalcFibNum(num - 1) + CalcFibNum(num - 2);
}