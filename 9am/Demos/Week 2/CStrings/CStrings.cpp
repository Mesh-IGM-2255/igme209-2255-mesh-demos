// CStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS // disable deprecation warnings for 
								// cstring functions in MS compilers


#include <iostream>
#include <cstring>

using namespace std;


int main()
{
	// cstring == "c style string"

	// "Shiro"
	// char name[5]; // garbage
	char name[6] = "Shiro";
	cout << name << endl;

	char stuff[2] = { 'a','b' };
	cout << stuff << endl; // no null term == BAD

	char first[6] = "Lacy ";
	char last[5] = "Mesh";
	char full[10] = "?";

	// "_s" versions are MS only - https://cplusplus.com/forum/beginner/118771/
	// You can use them, but PE autotests will replace with the gcc versions (non _s)
	// so make sure you're using memory safely!
	// To compile in VS without _s versions, defines _CRT_SECURE_NO_WARNINGS 
	// as a preprocessor directive (see top of file)
	// https://learn.microsoft.com/en-us/cpp/c-runtime-library/security-features-in-the-crt?view=msvc-170
	strcpy(full, first);
	cout << full << endl;

	strcat(full, last);
	cout << full << endl;

	// input
	char username[100];
	cout << "Enter your name: ";
	cin.getline(username, 100);

	char input;
	cout << "Letter: ";
	cin >> input;
	cout << input << endl;
	cin >> input;
	cout << input << endl;
	cin >> input;
	cout << input << endl;

	// See HW1 writeup for how to only get ONE char and ignore others until
	// the next newline
}

