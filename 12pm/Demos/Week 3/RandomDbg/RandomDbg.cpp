// RandomDbg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;

void printChars(char word[]);
void doStuff(int num);

int main()
{
	char name[6] = "Shiro";
	cout << name << endl;

	name[5] = '!';
	cout << name << endl;

	printChars(name);
	//doStuff(1);

	cout << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl << endl;

	srand(42);
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl << endl;

	srand(time(NULL));
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl << endl;

	cout << RAND_MAX << endl;
	cout << INT_MAX << endl;

	cout << 1.0 * rand() / RAND_MAX << endl;
	cout << (1.0 * rand() / RAND_MAX) * 100 << endl; // [0,100)
	cout << (1.0 * rand() / RAND_MAX) * 30 + 20 << endl; // [20,50)

}

void printChars(char word[])
{
	for (int i = 0; i < 15; i++)
	{
		cout << (i+1) << ": " << word[i] << endl;
	}
}


void doStuff(int num)
{
	doStuff(num + 1);
}