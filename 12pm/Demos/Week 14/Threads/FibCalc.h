#pragma once

#include <mutex>

// Making this a class solely to show how to use classes w/ threads
class FibCalc
{
public:
	void PrintFibNum(int num);
	void PrintFibNumMtx(int num, std::mutex* mtx);

	// helper function
	unsigned int CalcFibNum(int num);
};