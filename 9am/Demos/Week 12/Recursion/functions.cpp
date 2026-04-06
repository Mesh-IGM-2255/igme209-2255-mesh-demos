#include "functions.h"

#include <iostream>

unsigned int factorial_for(unsigned int num)
{
	unsigned int product = 1;
	for (unsigned int i = 2; i <= num; ++i)
	{
		product *= i;
	}

	return product;
}

unsigned int factorial_better(unsigned int num)
{
	unsigned int product = 1;

	// Don't really need an i
	// Little things like this, done everywhere, add up
	while (num > 1)
	{
		product *= num;
		num--;
	}

	return product;
}

unsigned int factorial_recursive(unsigned int num)
{
	// calls itself -- recursive case
	if (num >= 1)
	{
		// get to a -- state change to move towards base case
		return num * factorial_recursive(num - 1);
	}
	// solution -- base case
	else
	{
		return 1;
	}
}

unsigned int fib_iter(unsigned int num)
{
	if (num <= 2)
	{
		return num;
	}

	// last 2 terms
	unsigned int oneBack = 1;
	unsigned int twoBack = 1;
	unsigned int nextTerm;

	// loop until our num
	for (int i = 3; i <= num; ++i)
	{
		nextTerm = oneBack + twoBack;
		twoBack = oneBack;
		oneBack = nextTerm;
	}
	return nextTerm;
}

unsigned int fib_recursive(unsigned int num)
{
	// base case
	if (num <= 2)
	{
		return 1;
	}

	// recursive case
		// state change
	else
	{
		return fib_recursive(num - 1) + fib_recursive(num - 2);
	}
}

unsigned int fib_recursive(unsigned int num, unsigned int& numCalls)
{
	numCalls++;
	//std::cout << ".";

	// base case
	if (num <= 0)
	{
		return 0;
	}
	if (num <= 2)
	{
		return 1;
	}

	// recursive case
		// state change
	else
	{
		return fib_recursive(num - 1, numCalls) + fib_recursive(num - 2, numCalls);
	}
}

unsigned int fibonacci_cached(unsigned int num, unsigned int* cache, unsigned int& count)
{
	count++;

	// base case is I calculated this before
	if (cache[num] != 0)
	{
		return cache[num];
	}

	// otherwise, recursively calculate it
	if (num <= 0)
	{
		cache[num] = 0;
	}
	else if (num <= 2)
	{
		cache[num] = 1;
	}
	else
	{
		cache[num] = fibonacci_cached(num - 1, cache, count) + fibonacci_cached(num - 2, cache, count);
	}

	return cache[num];
}