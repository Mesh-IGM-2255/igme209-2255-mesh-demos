// RandomAndDbg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printChars(char name[]);
void doStuff(int num);

int main()
{
	char name[6] = "Shiro";
	name[5] = '!';
	cout << name << endl;

	printChars(name);
	doStuff(10);
	cout << endl << endl;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl << endl;

	srand(42);
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl << endl;

	srand(time(NULL));
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl << endl;
	cout << RAND_MAX << endl;
	cout << INT_MAX << endl;
	cout << ((rand()*1.0)/RAND_MAX)*100 << endl; // [0,100)
	cout << ((rand() * 1.0) / RAND_MAX) * 10 + 10  << endl; // [10,20) --- shift
}

void printChars(char name[])
{
	for (int i = 0; i < 10; i++)
	{
		cout << (i + 1) << ": " << name[i] << endl;
	}
}

void doStuff(int num)
{
	cout << num << " ";
	if (num > 0)
	{
		doStuff(num - 1);
	}
}