#pragma once

#include <mutex>

class FibCalc
{
public:
	void PrintFibNum(int num);
	void PrintFibNumMtx(int num, std::mutex* mtx);

	// helper
	unsigned int CalcFibNum(int num);
};

