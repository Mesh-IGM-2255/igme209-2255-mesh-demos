// Recursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
#include "functions.h"

// function ptr def for factorial
typedef unsigned int (*IntCalc)(unsigned int);

void testFactorial(string label, IntCalc fact);
void testFibonacci(string label, IntCalc fibo);

int main()
{
	//testFactorial("Iterative Factorial (for)", factorial_for);
	//testFactorial("Iterative Factorial (while)", factorial_better);
	//testFactorial("Recursive Factorial", factorial_recursive);

	testFibonacci("Iterative Fibonacci", fib_iter);
	//testFibonacci("Recursive Fibonacci", fib_recursive);

	unsigned int num = 45;
	cout << endl;
	unsigned int numCalls = 0;
	auto start = chrono::high_resolution_clock::now();
	cout << "Fib(" << num << ") - recursive: " << fib_recursive(num, numCalls) << endl;
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "\tNum calls: " << numCalls << endl;
	cout << "\tTime taken: " << duration.count() << " ms" << endl;

	cout << endl;

	unsigned int cache[50] = { 0 }; // ****************

	unsigned int count = 0;
	start = chrono::high_resolution_clock::now();
	cout << "Fib(" << num << ") - cached: " << fibonacci_cached(num, cache, count) << endl;
	end = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "\tCount: " << count << endl;
	cout << "\tTime taken: " << duration.count() << " miilliseconds" << endl;
}

void testFibonacci(string label, IntCalc fibo)
{
	cout << endl << label << endl;
	cout << "\t5th Fibonacci = " << fibo(5) << endl;
	cout << "\t7th Fibonacci = " << fibo(7) << endl;
	cout << "\t10th Fibonacci = " << fibo(10) << endl;
	cout << "\t45th Fibonacci = " << fibo(45) << endl;
}

void testFactorial(string label, IntCalc fact)
{
	cout << endl << label << endl;
	cout << "\t5! = " << fact(5) << endl;
	cout << "\t7! = " << fact(7) << endl;
	cout << "\t13! = " << fact(13) << endl;
}
