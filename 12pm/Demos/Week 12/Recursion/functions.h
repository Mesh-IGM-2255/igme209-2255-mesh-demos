#pragma once

// Goal is to compare and contrast implementations of the same logic iteratively and recursively

// Factorials
// n! = n * (n-1)!
// 5! = 5 * 4! = 5 * 4 * 3 * 2 * 1 = 120
unsigned int factorial_for(unsigned int num);
unsigned int factorial_better(unsigned int num);
unsigned int factorial_recursive(unsigned int num);


unsigned int fib_iter(unsigned int num);
unsigned int fib_recursive(unsigned int num);
unsigned int fib_recursive(unsigned int num, unsigned int& numCalls);
unsigned int fibonacci_cached(unsigned int num, unsigned int* cache, unsigned int& count);